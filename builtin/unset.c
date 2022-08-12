/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:56:28 by agunes            #+#    #+#             */
/*   Updated: 2022/08/12 17:17:47 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	unset2(void)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	while (g_shell->commandlist[i])
	{
		if (!envsearch(g_shell->commandlist[i]))
		{
			temp = g_shell->envflag;
			free(g_shell->env[temp]);
			while (g_shell->env[temp])
			{
				g_shell->env[temp] = g_shell->env[temp + 1];
				temp++;
			}
		}
		i++;
	}
}

int	unset(void)
{
	int	i;
	int	temp;

	i = 0;
	while (g_shell->commandlist[++i])
	{
		if (equalcheck(g_shell->commandlist[i]))
			temp = -1;
		exportsearch(g_shell->commandlist[i]);
		if (g_shell->exportflag != 0 && temp != -1)
		{
			temp = g_shell->exportflag;
			free(g_shell->export[g_shell->exportflag]);
			while (g_shell->export[temp])
			{
				g_shell->export[temp] = g_shell->export[temp + 1];
				temp++;
			}
		}
		unset2();
	}
	return (1);
}
