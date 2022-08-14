/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:27:38 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/14 06:14:25 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_op.h"

char	**ft_merge2(t_op *file)
{
	char	*res;
	int		i;

	i = 0;
	while (file->cmd_list[i])
		i++;
	res = malloc(2048);
	i = 0;
	while (file->cmd_list[i])
	{
		while (file->cmd_list[i + 1] && !operator_check(file->cmd_list[i]))
		{
			res = ft_strjoin(res, file->cmd_list[i]);
			if (!operator_check(file->cmd_list[i]))
				res = ft_strjoin(res, " ");
			i++;
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
