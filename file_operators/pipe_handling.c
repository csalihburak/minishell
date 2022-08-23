/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:49:03 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/23 17:48:54 by scoskun          ###   ########.fr       */
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
	temp = ft_split_quote(command, '|');
	file->fd_rd = -1;
	dbfree(g_shell->commandlist);
	ft_parser();
	runcommand(g_shell->commandlist[0]);
	return (command);
}

void	less_op_handling(t_op *file)
{
	int		i;
	int		pid;
	int		len;
	char	**temp;

	i = -1;
	len = dblen2(file->cmd_list);
	while (file->ops[++i])
	{
		if (!ft_strcmp(file->ops[i], "<"))
		{
			temp = ft_split_quote(file->cmd_list[len - 1], ' ');
			pid = fork();
			if (pid == 0)
			{
				file->fd = open(temp[dblen2(temp) - 1], O_WRONLY);
				dup2(file->fd, 0);
				create_ops(file, file->cmd_list[0]);
			}
			else
				wait(NULL);
			dbfree(temp);
			return ;
		}
	}
}
