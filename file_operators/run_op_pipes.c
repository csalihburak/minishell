/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_op_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:34:16 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/14 02:51:56 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_op.h"

void	ft_close2(int *arr)
{
	close(arr[1]);
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
				ft_close2(file->pipes[i]);
			}
			else if (i + 1 == file->pipe_flag)
			{
				file->fd = open("a", O_CREAT | O_RDWR, 0644);
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
	}
}
