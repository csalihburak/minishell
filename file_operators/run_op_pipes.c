/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_op_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:37:00 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/25 11:41:00 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_op.h"

int	file_creater(t_op *file)
{
	int		i;
	char	*a;

	i = 0;
	while (file->cmd_list[i + 1])
		i++;
	check_and_create(file, 0);
	if (ft_strchr(file->cmd_list[i], '|'))
		pipe_handling(file, file->cmd_list[i]);
	a = ft_strtrim(file->cmd_list[i], " ");
	if (!ft_strcmp(file->ops[i - 1], ">"))
		return (open(a, O_WRONLY | O_CREAT | O_TRUNC, 0644));
	else if (!ft_strcmp(file->ops[i - 1], ">>"))
		return (open(a, O_WRONLY | O_CREAT | O_APPEND, 0644));
	return (-1);
}

void	run_run(t_op *file, int i)
{
	if (i == 0)
	{
		dup2(file->pipes[i + 1][1], 1);
		close(file->pipes[i][1]);
	}
	else if (i + 1 == file->pipe_flag)
	{
		dup2(file->pipes[i][0], 0);
		dup2(file_creater(file), 1);
		close(file->pipes[i][1]);
		close(file->pipes[i][0]);
	}
	else
	{
		dup2(file->pipes[i][0], 0);
		dup2(file->pipes[i + 1][1], 1);
		close(file->pipes[i][1]);
	}
}

void	run_ops(t_op *file, int i)
{
	while (++i < file->pipe_flag)
	{
		file->pids[i] = fork();
		if (file->pids[i] == 0)
		{
			run_run(file, i);
			create_ops(file, file->pipe_list[i]);
			kill(getpid(), SIGTERM);
		}
		close(file->pipes[i][1]);
		close(file->pipes[i][0]);
	}
}
