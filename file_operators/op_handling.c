/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:27:38 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/26 13:29:34 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_op.h"

int	create_file(char *arr, char *op)
{
	int		fd;
	char	*a;

	fd = -1;
	a = ft_strtrim(arr, " ");
	if (!ft_strcmp(op, ">"))
		fd = open(a, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (!ft_strcmp(op, ">>"))
		fd = open(a, O_WRONLY | O_CREAT | O_APPEND, 0644);
	free(a);
	return (fd);
}

void	check_and_create(t_op *file, int flag)
{
	int		i;
	char	**temp;

	i = 0;
	temp = 0;
	if (flag == 0)
	{
		check_exec(file);
	}
	if (flag == 1)
	{
		check_exec(file);
		while (file->cmd_list[i + 1])
			i++;
		if (quote_strchr(file->cmd_list[i], '|'))
			file->cmd_list[i] = pipe_handling(file, file->cmd_list[i]);
		file->fd = create_file(file->cmd_list[i], file->ops[i - 1]);
		temp = ft_split_quote(file->cmd_list[0], ' ');
		file->path = path(file->path, temp[0]);
		file_run(file, temp, temp[0]);
		dbfree(file->path);
		dbfree(temp);
	}
}

void	norm_handle(t_op *file)
{
	int	i;

	i = -1;
	file->flag = 0;
	file->cmd_list = ft_split_quote(file->command, '>');
	while (file->cmd_list[++i])
		file->cmd_list[i] = deletechar(file->cmd_list[i], '"');
	if (!quote_strchr(file->cmd_list[0], '<') && \
	!quote_strchr(file->cmd_list[0], '|'))
		check_and_create(file, 1);
	else
		file->flag = 1;
}

void	op_handle(char *command)
{
	t_op	*file;
	int		i;

	i = -1;
	file = ft_calloc(sizeof(t_op), 1);
	file->command = command;
	op_list(file);
	if (quote_strchr(command, '>'))
		norm_handle(file);
	else if (quote_strchr(command, '<'))
	{
		file->cmd_list = ft_split_quote(command, '<');
		while (file->cmd_list[++i])
			file->cmd_list[i] = deletechar(file->cmd_list[i], '"');
		less_op_handling(file);
	}
	if (file->flag)
	{
		op_check(file);
		op_setup(file);
		dbfree(file->pipe_list);
	}
	dbfree(file->cmd_list);
	dbfree(file->ops);
	free(file);
}
