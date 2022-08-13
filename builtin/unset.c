/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:56:28 by agunes            #+#    #+#             */
/*   Updated: 2022/08/13 21:18:58 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	envunset(char *commandlist)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	if (!envsearch(commandlist) && g_shell->unsetflag != 1)
	{
		temp = g_shell->envflag;
		free(g_shell->env[temp]);
		while (g_shell->env[temp])
		{
			g_shell->env[temp] = g_shell->env[temp + 1];
			temp++;
		}
	}
}

void	exportunset(char *commandlist)
{
	int	i;
	int	len;
	int	temp;

	i = -1;
	temp = 0;
	len = ft_strlen(commandlist);
	while (g_shell->export[++i])
	{
		if (!ft_strncmp(g_shell->export[i], commandlist, len))
		{
			if (g_shell->export[i][len] == '\0' || \
			g_shell->export[i][len] == '=')
			{
				temp = i;
				free(g_shell->export[temp]);
				while (g_shell->export[temp])
				{
					g_shell->export[temp] = g_shell->export[temp + 1];
					temp++;
				}
			}
		}
	}
}

int	unset(void)
{
	int		i;
	char	*buff;

	i = 0;
	buff = ft_strdup("minishell: unset: `");
	while (g_shell->commandlist[++i])
	{
		if (equalcheck(g_shell->commandlist[i]))
		{
			buff = ft_strjoin(buff, g_shell->commandlist[i]);
			buff = ft_strjoin(buff, "'");
			buff = ft_strjoin(buff, ": not a valid identifier");
			write(2, buff, ft_strlen(buff));
			write(1, "\n", 1);
			free(buff);
			if (g_shell->commandlist[i + 1])
				i++;
		}
		exportunset(g_shell->commandlist[i]);
		envunset(g_shell->commandlist[i]);
	}
	return (1);
}
