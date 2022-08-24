/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dolarutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:10:25 by agunes            #+#    #+#             */
/*   Updated: 2022/08/24 13:11:58 by agunes           ###   ########.fr       */
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

char	*lastexe(void)
{
	char	*buff;

	buff = ft_strdup(g_shell->lastexe);
	free(g_shell->lastexe);
	return (buff);
}

int	singlequo(char *command)
{
	int	i;

	i = 0;
	if (command[i] == '\'')
	{
		while (command[i])
			i++;
		if (command[i - 1] == '\'')
			return (0);
	}
	return (1);
}

void	cmdlistup2(char *first, int i)
{
	int	y;
	int	len;

	y = -1;
	len = 0;
	while (g_shell->buff[++y])
	{
		len = ft_strlen(first);
		if (!ft_strncmp(g_shell->buff[y], first, len))
		{
			if (g_shell->buff[y][len])
			{
				if (g_shell->buff[y] != (void *)0)
					free(g_shell->buff[y]);
				g_shell->buff[y] = ft_strdup(" ");
			}
			else
			{
				if (g_shell->buff[y] != (void *)0)
					free(g_shell->buff[y]);
				g_shell->buff[y] = ft_strdup(g_shell->env[i] + \
				findfirstindex(g_shell->env[i], '=') + 1);
			}
		}
	}
}

char	*cmdlistup(char *command)
{
	int		i;
	int		x;
	char	*first;

	i = -1;
	x = -1;
	g_shell->buff = ft_split(command, '$');
	while (g_shell->env[++i])
	{
		x = -1;
		first = ft_calloc(100, 1);
		if (ft_strchr(g_shell->env[i], '='))
		{
			while (g_shell->env[i][++x] && g_shell->env[i][x] != '=')
				first[x] = g_shell->env[i][x];
			first[x] = '\0';
		}
		cmdlistup2(first, i);
		free(first);
	}
	first = merge(g_shell->buff, 0);
	dbfree(g_shell->buff);
	free(command);
	return (first);
}
