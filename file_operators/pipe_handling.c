/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:49:03 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/22 12:47:57 by scoskun          ###   ########.fr       */
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
	int		len;
	char	**temp;

	i = -1;
	len = dblen2(file->cmd_list);
	while (file->ops[++i])
	{
		if (!ft_strcmp(file->ops[i], "<"))
		{
			temp = ft_split_quote(file->cmd_list[len - 1], ' ');
			file->cmd_list[0] = ft_strjoin(file->cmd_list[0], " ");
			file->cmd_list[0] = ft_strjoin(file->cmd_list[0], temp[0]);
			create_ops(file, file->cmd_list[0]);
			dbfree(temp);
			return ;
		}
	}
}
