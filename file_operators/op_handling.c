/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:27:38 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/11 18:06:47 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_op.h"

void	ft_path2(t_op *file)
{
	int		i;

	i = -1;
	while (g_shell->env[++i])
	{
		if (ft_strncmp(g_shell->env[i], "PATH", 4) == 0)
			break ;
	}
	file->path = ft_split(g_shell->env[i], ':');
	free(file->path[0]);
	file->path[0] = ft_strdup((ft_strchr(file->path[0], '=') + 1));
	i = -1;
	while (file->path[++i])
	{
		file->path[i] = ft_strjoin(file->path[i], "/");
		file->path[i] = ft_strjoin(file->path[i], \
		file->cmd_list[0]);
	}
	i = -1;
}

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
	while (file->cmd_list[i])
		free(file->cmd_list[i++]);
	free(file->cmd_list);
	return (ft_split(res, '\"'));
}

void	op_handle(char *command)
{
	t_op	*file;
	int		i;

	i = 0;
	file = malloc(sizeof(t_op));
	file->cmd_list = ft_split(command, ' ');
	file->cmd_list = merge(file);
	ft_path2(file);
}