/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_op_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:34:16 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/15 19:55:59 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_op.h"

int	file_creater(t_op *file)
{
	int		i;
	int		j;
	char	*a;

	i = 0;
	j = 0;
	while (file->cmd_list[i + 1])
		i++;
	check_exec(file);
	printf("selam\n");
	a = ft_strtrim(file->cmd_list[i], " ");
	if (!ft_strcmp(file->ops[0], ">"))
		return (open(a, O_WRONLY | O_CREAT | O_TRUNC, 0600));
	else if (!ft_strcmp(file->ops[0], ">>"))
		return (open(a, O_APPEND | O_RDWR, 0777));
	return (-1);
}

void	run_ops(t_op *file, int i)
{
	while (++i < file->pipe_flag)
	{
		file->pids[i] = fork();
		if (file->pids[i] == 0)
		{
			if (i == 0)
			{
				dup2(file->pipes[i + 1][1], 1);
				close(file->pipes[i][1]);
			}
			else if (i + 1 == file->pipe_flag)
			{
				file->fd = file_creater(file);
				printf("fd = %d\n", file->fd);
				dup2(file->pipes[i][0], 0);
				dup2(file->fd, 1);
				close(file->pipes[i][1]);
			}
			else
			{
				dup2(file->pipes[i][0], 0);
				dup2(file->pipes[i + 1][1], 1);
				close(file->pipes[i][1]);
			}
			create_ops(file, file->pipe_list[i]);
			kill(getpid(), SIGTERM);
			return ;
		}
		close(file->pipes[i][1]);
		close(file->pipes[i][0]);
	}
}
