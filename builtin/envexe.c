/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envexe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:00:42 by agunes            #+#    #+#             */
/*   Updated: 2022/08/10 16:12:00 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_envexe(void)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen((g_shell->commandlist[0] + 1));
	while (g_shell->env[i])
	{
		if (!ft_strncmp(g_shell->commandlist[0] + 1, g_shell->env[i], len))
		{
			if (g_shell->env[i][len] == '=')
			{
				g_shell->envexe = ft_strdup(g_shell->env[i] + (len + 1));
				if (ft_builtinsearch(g_shell->envexe) == 0)
				{
					ft_path(g_shell->envexe);
					g_shell->pathflag = 1;
					ft_searchfor(g_shell->envexe);
					g_shell->free_flag = 1;
				}
				g_shell->pathflag = 0;
				free(g_shell->envexe);
				break ;
			}
		}
		i++;
	}
	ft_builtfree();
	g_shell->free_flag = 1;
	return (1);
}
