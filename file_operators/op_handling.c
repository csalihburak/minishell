/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:27:38 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/18 13:58:16 by scoskun          ###   ########.fr       */
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
	int		fd;
	char	**buff;

	fd = 0;
	i = 0;
	buff = 0;
	if (flag == 0)
	{
		check_exec(file);
	}
	if (flag == 1)
	{
		buff = ft_split(file->cmd_list[0], ' ');
		file->path = path(file->path, buff[0]);
		check_exec(file);
		file_run(file, buff, buff[0]);
		dbfree(buff);
		dbfree(file->path);
	}
}

void	op_handle(char *command)
{
	t_op	*file;

	file = malloc(sizeof(t_op));
	command = merge(g_shell->commandlist, 1);
	file->command = command;
	if (ft_strchr(command, '>'))
		file->cmd_list = ft_split(command, '>');
	if (ft_strchr(command, '<'))
		file->cmd_list = ft_split(command, '<');
	op_list(file);
/* 	if (op_check(file))
	{
		op_setup(file);
		dbfree(file->pipe_list);
	}
	else */
		check_and_create(file, 1);
	dbfree(g_shell->commandlist);
	dbfree(file->cmd_list);
	dbfree(file->ops);
	free(command);
	free(file);
}
