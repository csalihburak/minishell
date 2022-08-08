/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envexe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:00:42 by agunes            #+#    #+#             */
/*   Updated: 2022/08/08 17:09:37 by agunes           ###   ########.fr       */
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
			g_shell->envexe = ft_strdup(g_shell->env[i] + (len + 1));
			ft_builtfree();
			runcommand(g_shell->envexe);
			free(g_shell->envexe);
			break ;
		}
		i++;
	}
	return (1);
}
