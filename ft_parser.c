/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:06:45 by agunes            #+#    #+#             */
/*   Updated: 2022/08/09 19:44:52 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check(void)
{
	int	i;
	int	d;
	int	s;

	d = 0;
	s = 0;
	i = 0;
	while (g_shell->command && g_shell->command[i])
	{
		if (g_shell->command[i] == '\"')
			d++;
		else if (g_shell->command[i] == '\'')
			s++;
		i++;
	}
	if (d % 2 != 0 || s % 2 != 0)
		return (-1);
	if (d != 0)
		return (0);
	return (0);
}

char	**splt(char *command)
{
	int		i;
	int		j;
	int		k;
	char	**cmd;

	i = -1;
	k = 0;
	j = 0;
	cmd = spltnorm(command, i, k, j);
	free(command);
	return (cmd);
}

char	**splt2(char *command)
{
	int		i;
	int		j;
	int		k;
	char	**cmd;

	i = 0;
	k = 0;
	j = 0;
	cmd = splt2norm(command, i, k, j);
	free(command);
	return (cmd);
}

char	*merge(char **command)
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
		while (command[i][j])
			arr[k++] = command[i][j++];
		if (command[i + 1])
			arr[k++] = ' ';
		i++;
	}
	arr[k] = '\0';
	return (arr);
}

void	ft_parser(void)
{
	int		i;

	i = 0;
	if (ft_strchr(g_shell->command, '|'))
	{
		g_shell->pipe_flag = 1;
		g_shell->commandlist = ft_split(g_shell->command, '|');
		while (g_shell->commandlist[++i])
			g_shell->pipe_flag++;
	}
	else if (ft_check() == 0)
	{
		g_shell->commandlist = ft_split(g_shell->command, ' ');
		g_shell->pipe_flag = 0;
	}
}
