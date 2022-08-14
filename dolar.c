/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dolar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:04:49 by agunes            #+#    #+#             */
/*   Updated: 2022/08/14 16:47:39 by agunes           ###   ########.fr       */
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

char	*merge2(char **command)
{
	char	*arr;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	arr = malloc(sizeof(char) * dblen(command));
	while (command[i])
	{
		j = 0;
		if (command[i][0] == '1' && command[i][1] == '\0')
			if (command[i + 1])
				i++;
		while (command[i][j])
			arr[k++] = command[i][j++];
		i++;
	}
	arr[k] = '\0';
	return (arr);
}

char	*cmdlistup(char *command)
{
	int		i;
	char	*temp;
	char	**buff;

	i = -1;
	buff = ft_split(command, '$');
	while (buff[++i])
	{
		if (!envsearch(buff[i]))
		{
			free(buff[i]);
			buff[i] = ft_strdup(g_shell->env[g_shell->envflag] + \
			findindex(g_shell->env[g_shell->envflag], '=') + 1);
		}
		else
		{
			free(buff[i]);
			buff[i] = ft_strdup("");
		}
	}
	temp = merge2(buff);
	free(command);
	dbfree(buff);
	return (temp);
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
