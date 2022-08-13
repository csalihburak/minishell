/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dolar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:04:49 by agunes            #+#    #+#             */
/*   Updated: 2022/08/13 23:51:39 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	dolarfind(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] == '$')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*cmdlistup(char *command)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	j = -1;
	while (command[i] != '$')
		i++;
	i++;
	buff = malloc(sizeof(char) * i + 1);
	while (command[++j] != '$')
		buff[j] = command[j];
	buff[j] = '\0';
	if (!envsearch(command + i))
		buff = ft_strjoin(buff, (g_shell->env[g_shell->envflag] + \
		findindex(g_shell->env[g_shell->envflag], '=')));
	else
		buff = ft_strjoin(buff, command + dolarfind(command));
	free(command);
	return (buff);
}

char	*lastexe(void)
{
	char	*buff;

	buff = ft_strdup(g_shell->lastexe);
	free(g_shell->lastexe);
	return (buff);
}

int	dolar(void)
{
	int		i;
	char	*temp;

	i = 0;
	g_shell->freeflag = 0;
	while (g_shell->commandlist[i])
	{
		if (commandsearch(g_shell->commandlist[i], "$_"))
		{
			g_shell->freeflag = 1;
			free(g_shell->commandlist[i]);
			g_shell->commandlist[i] = lastexe();
		}
		else if (dolarfind(g_shell->commandlist[i]))
			g_shell->commandlist[i] = cmdlistup(g_shell->commandlist[i]);
		i++;
	}
	while (g_shell->commandlist[i])
		i++;
	temp = g_shell->lastexe;
	g_shell->lastexe = ft_strdup(g_shell->commandlist[i - 1]);
	if (g_shell->freeflag != 1)
		free(temp);
	return (1);
}
