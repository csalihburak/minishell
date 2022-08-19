/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:49:03 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/19 15:26:57 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_op.h"

char	*pipe_handling(t_op *file, char *command)
{
	char	**temp;
	int		i;
	int		k;

	k = 0;
	i = 0;
	temp = ft_split(command, '|');
	file->fd_rd = -1;
	g_shell->command = ft_strdup((ft_strchr(command, '|') + 1));
	free(command);
	command = ft_strdup(temp[0]);
	dbfree(g_shell->commandlist);
	ft_parser();
	runcommand(g_shell->commandlist[0]);
	return (command);
}
