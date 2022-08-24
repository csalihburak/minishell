/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:49:03 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/24 11:02:20 by scoskun          ###   ########.fr       */
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
	char	**temp;

	i = -1;
	while (file->ops[++i])
	{
		if (!ft_strcmp(file->ops[i], "<"))
		{
			temp = ft_split_quote(file->command, ' ');
			pid = fork();
			if (pid == 0)
			{
				file->fd = open(temp[dblen2(temp) - 1], O_RDONLY);
				dup2(file->fd, 0);
				close(file->fd);
				create_ops(file, file->cmd_list[0]);
				kill(getpid(), SIGTERM);
			}
			else
				wait(NULL);
			dbfree(temp);
			return ;
		}
	}
}
