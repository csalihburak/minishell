/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_op_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:34:16 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/12 21:02:34 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_op.h"

void	ft_close2(int *arr)
{
	close(arr[0]);
	close(arr[1]);
}

void	ft_dup2(int i)
{
	dup2(g_shell->pipes[i][0], 0);
	if (i + 1 != g_shell->pipe_flag)
		dup2(g_shell->pipes[i + 1][1], 1);
	ft_close2(g_shell->pipes[i]);
}

void	run_ops(t_op *file, int i)
{
	int	fd = open("a", O_RDWR);
	printf("pipeflag = %d fd = %d\n", file->pipe_flag, fd);
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
				dup2(file->pipes[i][0], 0);
				dup2(file->pipes[i + 1][1], 1);
				close(file->pipes[i][1]);
				close(file->pipes[i][0]);
			}
			else
				ft_dup2(i);
			create_ops(file, file->pipe_list[i]);
			kill(getpid(), SIGTERM);
			return ;
		}
		ft_close2(file->pipes[i]);
	}
	close(fd);
}