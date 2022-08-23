/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:00:33 by agunes            #+#    #+#             */
/*   Updated: 2022/08/23 13:09:44 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	addexport(char *command)
{
	int		i;

	i = 0;
	while (g_shell->export[i])
		i++;
	if (equalcheck(command) == 1)
	{
		command = addquote(command, 0);
		g_shell->export[i] = ft_strdup(command);
		g_shell->export[i + 1] = NULL;
		free(command);
	}
	else
	{
		g_shell->export[i] = ft_strdup(command);
		g_shell->export[i + 1] = NULL;
	}
}

void	addenv(char *command)
{
	int		i;
	char	*temp;

	i = 0;
	while (g_shell->env[i])
		i++;
	temp = g_shell->env[i - 1];
	g_shell->env[i] = temp;
	g_shell->env[i - 1] = ft_strdup(command);
	g_shell->env[i + 1] = NULL;
}

void	envupdate(char *command)
{
	int	i;

	i = g_shell->envflag;
	free(g_shell->env[i]);
	g_shell->env[i] = ft_strdup(command);
}

int	exportupdate(char *command)
{
	int	i;

	i = g_shell->exportflag;
	if (g_shell->exportflag != 0)
	{
		if (equalcheck(command))
		{
			free(g_shell->export[i]);
			g_shell->export[i] = addquote(command, 0);
		}
		return (1);
	}
	return (0);
}
