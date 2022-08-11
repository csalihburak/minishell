/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:00:33 by agunes            #+#    #+#             */
/*   Updated: 2022/08/11 16:41:36 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	addexport(char *commandlist)
{
	char	*buff;
	char	*temp;
	int		i;

	i = 0;
	buff = merge(g_shell->export);
	while (g_shell->export[i])
		free(g_shell->export[i++]);
	free(g_shell->export);
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
	free(g_shell->env[g_shell->envflag]);
	g_shell->env[g_shell->envflag] = ft_strdup(commandlist);
}

int	ft_export(void)
{
	int	i;

	i = 1;
	while (g_shell->commandlist[i])
	{
		if (envsearch(g_shell->commandlist[i]))
			if (equalcheck(g_shell->commandlist[i]))
				addenv(g_shell->commandlist[i]);
		if (exportsearch(g_shell->commandlist[i]))
			addexport(g_shell->commandlist[i]);
		if (!envsearch(g_shell->commandlist[i]))
			envupdate(g_shell->commandlist[i]);
		i++;
	}
	return (1);
}
