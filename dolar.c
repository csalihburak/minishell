/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dolar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:04:49 by agunes            #+#    #+#             */
/*   Updated: 2022/08/28 18:36:10 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	test();
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

void	dolar2(int i)
{
	if (!ft_strcmp(g_shell->commandlist[i], "$?"))
	{
		free(g_shell->commandlist[i]);
		g_shell->commandlist[i] = ft_itoa(g_shell->status / 256);
	}
	if (!ft_strcmp(g_shell->commandlist[i], "$_"))
	{
		g_shell->freeflag = 1;
		free(g_shell->commandlist[i]);
		g_shell->commandlist[i] = lastexe();
	}
	else if (singlequo(g_shell->commandlist[i]) && \
	dolarfind(g_shell->commandlist[i]))
		g_shell->commandlist[i] = cmdlistup(g_shell->commandlist[i]);
}

int	dolar(void)
{
	int		i;
	char	*temp;

	i = -1;
	g_shell->freeflag = 0;
	while (g_shell->commandlist[++i])
		dolar2(i);
	temp = g_shell->lastexe;
	g_shell->lastexe = ft_strdup(g_shell->commandlist[i - 1]);
	if (g_shell->freeflag != 1)
		free(temp);
	return (1);
}
