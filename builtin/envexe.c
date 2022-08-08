/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envexe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:00:42 by agunes            #+#    #+#             */
/*   Updated: 2022/08/08 16:43:01 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_envexe(void)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen((g_shell->commandlist[0] + 1));
	if (g_shell->path)
	{
		while (g_shell->path[i])
			free(g_shell->path[i++]);
		free(g_shell->path);
		g_shell->free_flag = 1;
	}
	while (g_shell->env[i])
	{
		if (!ft_strncmp(g_shell->commandlist[0] + 1, g_shell->env[i], len))
		{
			g_shell->envexe = ft_strdup(g_shell->env[i] + (len + 1));
			runcommand(g_shell->envexe);
			free(g_shell->envexe);
			g_shell->free_flag = 0;
			break ;
		}
		i++;
	}
	i = 0;
	return (1);
}
