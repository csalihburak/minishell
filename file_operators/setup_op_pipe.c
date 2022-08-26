/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_op_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:35:33 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/26 13:35:47 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_op.h"

int	dblen2(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	op_list(t_op *file)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	file->ops = ft_calloc(sizeof(char *), 100);
	file->cmd_list = ft_split_quote(file->command, ' ');
	while (file->cmd_list [++i])
	{
		if (file->cmd_list[i][0] != '"' && !ft_strcmp(file->cmd_list[i], ">"))
			file->ops[j++] = ft_strdup(file->cmd_list[i]);
		if (file->cmd_list[i][0] != '"' && !ft_strcmp(file->cmd_list[i], ">>"))
			file->ops[j++] = ft_strdup(file->cmd_list[i]);
		if (file->cmd_list[i][0] != '"' && !ft_strcmp(file->cmd_list[i], "<"))
			file->ops[j++] = ft_strdup(file->cmd_list[i]);
		if (file->cmd_list[i][0] != '"' && !ft_strcmp(file->cmd_list[i], "<<"))
			file->ops[j++] = ft_strdup(file->cmd_list[i]);
	}
	dbfree(file->cmd_list);
	file->ops[j] = NULL;
}

void	op_setup(t_op *file)
{
	int	i;

	i = -1;
	file->pids = ft_calloc(sizeof(int), file->pipe_flag);
	file->pipes = ft_calloc(sizeof(int *), (file->pipe_flag));
	while (++i < (file->pipe_flag))
	{
		file->pipes[i] = ft_calloc(sizeof(int), 2);
		pipe(file->pipes[i]);
	}
	run_ops(file, -1);
	i = 0;
	while (i++ < file->pipe_flag)
		wait(NULL);
	i = -1;
	free(file->pids);
	i = 0;
	while (i < file->pipe_flag)
		free(file->pipes[i++]);
	free(file->pipes);
}
