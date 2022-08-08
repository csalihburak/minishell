/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:00:33 by agunes            #+#    #+#             */
/*   Updated: 2022/08/08 16:35:26 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	exportcheck(void)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (g_shell->commandlist[1][len] && \
	g_shell->commandlist[1][len] != '=')
		len++;
	while (g_shell->env[i])
	{
		if (!ft_strncmp(g_shell->env[i], g_shell->commandlist[1], len))
		{
			if (g_shell->env[i][len] == '=')
			{
				g_shell->exportflag = i;
				return (0);
			}
		}
		i++;
	}
	return (1);
}

void	addenv(void)
{
	int		i;
	char	*buff;

	i = 0;
	while (g_shell->env[i])
		i++;
	buff = g_shell->env[i - 1];
	g_shell->env[i - 1] = g_shell->env[i - 2];
	g_shell->env[i - 2] = buff;
}

void	exportupdate(void)
{
	free(g_shell->env[g_shell->exportflag]);
	g_shell->env[g_shell->exportflag] = ft_strdup(g_shell->commandlist[1]);
}

int	ft_export(void)
{
	int		i;
	char	*buff;
	char	*temp;

	if (exportcheck())
	{
		i = 0;
		buff = merge(g_shell->env);
		while (g_shell->env[i])
			free(g_shell->env[i++]);
		free(g_shell->env);
		buff = ft_strjoin(buff, " ");
		buff = ft_strjoin(buff, g_shell->commandlist[1]);
		temp = buff;
		g_shell->env = ft_split(buff, ' ');
		free(temp);
		addenv();
	}
	else
		exportupdate();
	return (1);
}
