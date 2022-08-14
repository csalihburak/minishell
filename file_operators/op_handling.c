/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:27:38 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/14 03:03:09 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_op.h"

char	**ft_merge2(t_op *file)
{
	char	*res;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (file->cmd_list[i])
		i++;
	res = malloc(2048);
	i = 0;
	while (file->cmd_list[i])
	{
		while (file->cmd_list[i + 1] && \
		!(ft_strncmp(file->cmd_list[i], ">>", 2) == 0 || \
		ft_strncmp(file->cmd_list[i], "<", 1) == 0 \
		|| ft_strncmp(file->cmd_list[i], "<<", 2) == 0 || \
		ft_strncmp(file->cmd_list[i], ">", 1) == 0))
		{
			res = ft_strjoin(res, file->cmd_list[i]);
			if (!(ft_strncmp(file->cmd_list[i + 1], ">>", 2) == 0 || \
			ft_strncmp(file->cmd_list[i + 1], "<", 1) == 0 \
			|| ft_strncmp(file->cmd_list[i + 1], "<<", 2) == 0 || \
			ft_strncmp(file->cmd_list[i + 1], ">", 1) == 0))
				res = ft_strjoin(res, " ");
			i++;
		}
		if (file->cmd_list[i])
		{
			res = ft_strjoin(res, "\"");
			res = ft_strjoin(res, file->cmd_list[i]);
			res = ft_strjoin(res, "\"");
		}
		i++;
	}
	dbfree(file->cmd_list);
	file->cmd_list = ft_split(res, '\"');
	free(res);
	return (NULL);
}

void	op_handle(char *command)
{
	t_op	*file;
	int		i;

	i = 0;
	file = malloc(sizeof(t_op));
	file->cmd_list = ft_split(command, ' ');
	ft_merge2(file);
	if (op_check(file))
	{
		op_setup(file);
		dbfree(file->pipe_list);
	}
	dbfree(g_shell->commandlist);
	dbfree(file->cmd_list);
	free(file);
}
