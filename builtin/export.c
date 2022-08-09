/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:00:33 by agunes            #+#    #+#             */
/*   Updated: 2022/08/09 20:40:19 by agunes           ###   ########.fr       */
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

void	exportedit(void)
{
	int		i;
	int		j;
	char	*buff;
	char	**temp;

	i = -1;
	j = 0;
	temp = malloc(sizeof(char *) * 100);
	while (g_shell->env[++i])
		temp[i] = ft_strdup(g_shell->env[i]);
	i = 0;
	while (temp[i])
	{
		j = 0;
		while (temp[j])
		{
			if (temp[j][0] > temp[i][0])
			{
				buff = temp[i];
				temp[i] = temp[j];
				temp[j] = buff;
			}
			j++;
		}
		i++;
	}
}

int	eqcheck(void)
{
	int	i;

	i = 0;
	if (g_shell->commandlist[1] == NULL)
		exportedit();
	while (g_shell->commandlist[1] && g_shell->commandlist[1][i])
		if (g_shell->commandlist[1][i++] == '=')
			return (0);
	return (1);
}

int	ft_export(void)
{
	int		i;
	char	*buff;
	char	*temp;

	g_shell->free_flag = 1;
	ft_builtfree();
	if (eqcheck())
		return (1);
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
