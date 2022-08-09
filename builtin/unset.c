/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:56:28 by agunes            #+#    #+#             */
/*   Updated: 2022/08/09 11:14:19 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	equal(void)
{
	int	i;

	i = 0;
	while (g_shell->commandlist[1][i])
	{
		if (g_shell->commandlist[1][i] == '=')
			return (i);
		i++;
	}
	return (0);
}

void	ft_unset2(void)
{
	int		i;
	int		len;

	len = ft_strlen(g_shell->commandlist[1]);
	i = 0;
	ft_builtfree();
	while (g_shell->env[i])
	{
		if (!ft_strncmp(g_shell->env[i], g_shell->commandlist[1], len))
		{
			if (g_shell->env[i][len] == '=')
			{
				while (g_shell->env[i++])
				{
					if (g_shell->env[i + 1])
						free(g_shell->env[i]);
					g_shell->env[i] = g_shell->env[i + 1];
				}
				break ;
			}			
		}
		i++;
	}
}

int	ft_unset(void)
{
	if (equal())
		printf("minishell: unset: `%s': not a valid identifier\n", \
		g_shell->commandlist[1]);
	else
		ft_unset2();
	return (1);
}
