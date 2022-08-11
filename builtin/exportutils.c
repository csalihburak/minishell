/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:00:33 by agunes            #+#    #+#             */
/*   Updated: 2022/08/11 18:47:49 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	addexport(char *commandlist)
{
	char	*buff;
	char	*temp;

	buff = merge(g_shell->export);
	dbfree(g_shell->export);
	buff = ft_strjoin(buff, " ");
	if (equalcheck(commandlist) == 1)
	{
		temp = addquote(commandlist);
		buff = ft_strjoin(buff, temp);
		free(temp);
		buff = ft_strjoin(buff, "\"");
	}
	else if (!ft_getenv(commandlist))
		buff = ft_strjoin(buff, commandlist);
	g_shell->export = ft_split(buff, ' ');
	free(buff);
}

void	addenv(char *commandlist)
{
	char	*buff;
	char	*temp;
	char	*temp2;
	int		i;

	i = 0;
	buff = merge(g_shell->env);
	while (g_shell->env[i])
		free(g_shell->env[i++]);
	free(g_shell->env);
	i = 0;
	buff = ft_strjoin(buff, " ");
	buff = ft_strjoin(buff, commandlist);
	g_shell->env = ft_split(buff, ' ');
	while (g_shell->env[i])
		i++;
	temp = ft_strdup(g_shell->env[i - 1]);
	temp2 = ft_strdup(g_shell->env[i - 2]);
	free(g_shell->env[i - 1]);
	free(g_shell->env[i - 2]);
	g_shell->env[i - 2] = temp;
	g_shell->env[i - 1] = temp2;
	free(buff);
}

void	envupdate(char *commandlist)
{
	int	i;

	i = g_shell->envflag;
	free(g_shell->env[i]);
	g_shell->env[i] = ft_strdup(commandlist);
}

void	exportupdate(char *commandlist)
{
	int	i;

	i = g_shell->exportflag;
	if (i != 0)
	{
		free(g_shell->export[i]);
		g_shell->export[i] = addquote(commandlist);
		g_shell->export[i] = ft_strjoin(g_shell->export[i], "\"");
	}
}
