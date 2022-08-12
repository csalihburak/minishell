/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:00:33 by agunes            #+#    #+#             */
/*   Updated: 2022/08/12 14:40:06 by agunes           ###   ########.fr       */
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
	else
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
	dbfree(g_shell->env);
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

int	exportcheck(char *arr)
{
	int	i;

	i = 0;
	if (!ft_isalpha(arr[0]) && arr[0] != '_')
		return (0);
	return (1);
}

int	exportupdate(char *commandlist)
{
	int	i;

	i = g_shell->exportflag;
	if (g_shell->exportflag != 0 && g_shell->unsetflag != 1)
	{
		if (equalcheck(commandlist))
		{
			free(g_shell->export[i]);
			g_shell->export[i] = addquote(commandlist);
			g_shell->export[i] = ft_strjoin(g_shell->export[i], "\"");
		}
		return (1);
	}
	return (0);
}
