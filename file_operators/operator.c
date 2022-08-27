/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:50:20 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/27 15:53:00 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_op.h"

void	create_ops(t_op *file, char *command)
{
	file->pipe_command = ft_split_quote(command, ' ');
	file->path = path(file->path, file->pipe_command[0]);
	if (builtinsearch(file->pipe_command[0]) == 0)
	{
		searchfor(file->path, file->pipe_command, file->pipe_command[0]);
		checkerror(file->pipe_command[0]);
	}
	dbfree(file->pipe_command);
	dbfree(file->path);
}
