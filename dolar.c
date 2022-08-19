/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dolar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:04:49 by agunes            #+#    #+#             */
/*   Updated: 2022/08/15 05:23:29 by agunes           ###   ########.fr       */
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
	int		x;
	int		y;
	int		len;
	char	*first;
	char	**buff;

	i = 0;
	x = 0;
	y = 0;
	buff = ft_split(command, '$');
 	while (g_shell->env[i])
	{
		x = 0;
		y = 0;
		first = malloc(100);
		if (ft_strchr(g_shell->env[i], '='))
		{
			while(g_shell->env[i][x] && g_shell->env[i][x] != '=')
			{
				first[x] = g_shell->env[i][x];
				x++;
			}
			first[x] = '\0';
		}
		while (buff[y])
		{
			len = ft_strlen(first);
			if (!ft_strncmp(buff[y], first, len))
			{
				if (buff[y][len])
					buff[y] = ft_strdup(" ");
				else
					buff[y] = ft_strdup(g_shell->env[i] + findfirstindex(g_shell->env[i], '=') + 1);
			}
			y++;
 		}
		free(first);
		i++;
	}
	first = merge(buff, 0);
	free(buff);
	return (first);
}

char	*lastexe(void)
{
	char	*buff;

	buff = ft_strdup(g_shell->lastexe);
	free(g_shell->lastexe);
	return (buff);
}

int	testfind(char *command)
{
	int	i;

	i = 0;
	if(command[i] == '\'')
	{
		while(command[i])
			i++;
		if (command[i - 1] == '\'')
			return (0);
	}
	return (1);
}

int	dolar(void)
{
	int		i;
	char	*temp;

	i = 0;
	g_shell->freeflag = 0;
	while (g_shell->commandlist[i])
	{
		if (!ft_strcmp(g_shell->commandlist[i], "$_"))
		{
			g_shell->freeflag = 1;
			free(g_shell->commandlist[i]);
			g_shell->commandlist[i] = lastexe();
		}
		else if (testfind(g_shell->commandlist[i]) && dolarfind(g_shell->commandlist[i]))
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
