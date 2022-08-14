/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportutils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:25:57 by agunes            #+#    #+#             */
/*   Updated: 2022/08/15 01:04:42 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	findfirstindex(char *arr, char c)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	*addquote(char *commandlist, int status)
{
	int		i;
	char	*buff;

	i = 0;
	while (commandlist[i])
		i++;
	buff = malloc(sizeof(char) * (i + 3));
	i = 0;
	while (commandlist[i] != '=' && commandlist[i])
	{
		buff[i] = commandlist[i];
		i++;
	}
	buff[i] = '=';
	buff[i + 1] = '"';
	while (commandlist[i])
	{
		buff[i + 2] = commandlist[i + 1];
		i++;
	}
	buff[i + 1] = '"';
	buff[i + 2] = '\0';
	if (status == 1)
		free(commandlist);
	return (buff);
}

int	equalcheck(char *commandlist)
{
	int	i;

	i = 0;
	while (commandlist[i])
	{
		if (commandlist[i] == '=')
		{
			g_shell->unsetflag = 1;
			return (1);
		}
		i++;
	}
	g_shell->unsetflag = 0;
	return (0);
}

int	exportsearch(char *arr)
{
	int	i;
	int	len;

	i = -1;
	len = findfirstindex(arr, '=');
	while (g_shell->export[++i])
	{
		if (!ft_strncmp(g_shell->export[i], arr, len))
		{
			if (g_shell->export[i][len] == '=')
			{
				g_shell->exportflag = i;
				break ;
			}
		}
		if (!ft_strncmp(g_shell->export[i], arr, len) && \
		g_shell->export[i][len] == '\0')
		{
			g_shell->exportflag = i;
			break ;
		}
	}
	if (exportupdate(arr))
		return (0);
	return (1);
}

int	envsearch(char *arr)
{
	int		i;
	int		len;

	i = 0;
	g_shell->envflag = 0;
	len = findfirstindex(arr, '=');
	while (g_shell->env[i])
	{
		if (ft_strncmp(g_shell->env[i], arr, len) == 0)
		{
			if (g_shell->env[i][len] == '=')
			{
				g_shell->envflag = i;
				return (0);
			}
		}
		i++;
	}
	return (1);
}
