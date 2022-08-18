/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:49:03 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/18 14:17:43 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_op.h"

char	*pipe_handling(t_op *file, char *command)
{
	char	**temp;
	int		i;
	int		k;
	char	*cmd;

	k = 0;
	temp = ft_split(command, '|');
	file->fd_rd = 0;
	i = dblen2(temp) - 1;
	free(command);
	command = ft_strdup(temp[0]);
	cmd = merge(temp + 1, 1);
	g_shell->commandlist = ft_split(cmd, '|');
	g_shell->pipe_flag = 1;
	runcommand(cmd);
	return (command);
}
