/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_op_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:35:33 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/12 18:17:31 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_op.h"

void	op_setup(t_op *file)
{
	int	i;
	int	*pids;
	int	**pipes;

	i = 0;
	pids = malloc(sizeof(int) * file->pipe_flag);
	pipes = malloc(sizeof(int *) * file->pipe_flag);
	while (i < file->pipe_flag)
	{
		pipes[i] = malloc(sizeof(int) * 2);
		pipe(pipes[i++]);
	}
	file->pids = pids;
	file->pipes = pipes;
	run_ops(file, -1);
	i = 0;
	while (i++ < file->pipe_flag)
		wait(NULL);
}
