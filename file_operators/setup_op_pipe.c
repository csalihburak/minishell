/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_op_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:35:33 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/16 01:04:29 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_op.h"

void	op_setup(t_op *file)
{
	int	i;

	i = -1;
	file->pids = malloc(sizeof(int) * file->pipe_flag);
	file->pipes = malloc(sizeof(int *) * (file->pipe_flag));
	while (++i < (file->pipe_flag))
	{
		file->pipes[i] = malloc(sizeof(int) * 2);
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
