/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:26:44 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/10 17:58:24 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_builtfree(void)
{
	int	i;

	i = 0;
	if (g_shell->path)
	{
		while (g_shell->path[i])
			free(g_shell->path[i++]);
		free(g_shell->path);
		g_shell->free_flag = 1;
	}
}

void	ft_free(void)
{
	int	i;

	i = -0;
	if (g_shell->pipe_flag == 0 && g_shell->command[0] > 0)
	{
		if (g_shell->commandlist)
		{
			while (g_shell->commandlist && g_shell->commandlist[i])
				free(g_shell->commandlist[i++]);
			if (g_shell->commandlist)
				free(g_shell->commandlist);
		}
		i = 0;
		if (g_shell->path && g_shell->path[i] && g_shell->free_flag == 0)
		{
			while (g_shell->path[i])
				free(g_shell->path[i++]);
			if (g_shell->path)
				free(g_shell->path);
		}
	}
}
