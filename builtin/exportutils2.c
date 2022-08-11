/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportutils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:25:57 by agunes            #+#    #+#             */
/*   Updated: 2022/08/11 18:07:40 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	findindex(char *arr, char c)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*addquote(char *commandlist)
{
	int		i;
	char	*buff;

	i = 0;
	while (commandlist[i])
		i++;
	buff = malloc(sizeof(char) * (i + 2));
	i = -1;
	while (commandlist[++i] != '=')
		buff[i] = commandlist[i];
	buff[i] = '=';
	buff[i + 1] = '"';
	while (commandlist[i])
	{
		buff[i + 2] = commandlist[i + 1];
		i++;
	}
	buff[i + 2] = '\0';
	return (buff);
}

int	equalcheck(char *commandlist)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (commandlist[i])
	{
		if (commandlist[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	exportsearch(char *arr)
{
	int	i;
	int	len;
	int len2;

	i = 0;
	len = findindex(arr, '=');
	len2 = ft_strlen(arr);
	while (g_shell->export[i])
	{
		if (ft_strncmp(g_shell->export[i], arr, len) == 0)
		{
			printf("%s %c %d\n", g_shell->export[i], g_shell->export[i][len], len2);
			if (g_shell->export[i][len] == '=')
				return (0);
			if (g_shell->export[i][len2] == '\0')
				return (0);
		}
		i++;
	}
	return (1);
}

int	envsearch(char *arr)
{
	int		i;
	int		len;

	i = 0;
	len = findindex(arr, '=');

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
