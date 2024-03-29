/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:26:44 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/28 13:45:04 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(void)
{
	int	i;

	i = -0;
	if (g_shell->pipe_flag == 0 && g_shell->command[0] > 0 && \
	g_shell->op_flag == 0)
	{
		if (g_shell->commandlist)
		{
			while (g_shell->commandlist && g_shell->commandlist[i])
				free(g_shell->commandlist[i++]);
			if (g_shell->commandlist)
				free(g_shell->commandlist);
		}
		i = 0;
		if (g_shell->path != NULL && g_shell->path[i])
		{
			while (g_shell->path[i])
				free(g_shell->path[i++]);
			if (g_shell->path)
				free(g_shell->path);
		}
	}
}

void	dbfree(char **array)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (array != NULL && array[i])
	{
		x = 0;
		while (array[i][x])
			array[i][x++] = '\0';
		free(array[i++]);
	}
	free(array);
	array = NULL;
}
