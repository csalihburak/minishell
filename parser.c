/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:06:45 by agunes            #+#    #+#             */
/*   Updated: 2022/08/19 14:41:38 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*merge(char **command, int status)
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
		if (status == 1)
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
	char	*temp;

	i = -1;
	g_shell->commandlist = ft_implt_split(g_shell->command, ' ');
	while (g_shell->commandlist[++i])
	{
		temp = g_shell->commandlist[i];
		g_shell->commandlist[i] = deletechar(g_shell->commandlist[i], '"');
		free(temp);
	}
	free(g_shell->command);
	g_shell->command = merge(g_shell->commandlist, 1);
	i = 0;
	if (ft_strchr(g_shell->command, '>'))
	{
		g_shell->commandlist = ft_split(g_shell->command, ' ');
		g_shell->pipe_flag = 0;
		g_shell->op_flag = 1;
	}
	else if (ft_strchr(g_shell->command, '|'))
	{
		g_shell->pipe_flag = 1;
		g_shell->commandlist = ft_split(g_shell->command, '|');
		while (g_shell->commandlist[++i])
			g_shell->pipe_flag++;
	}
	else
	{
		g_shell->commandlist = ft_split(g_shell->command, ' ');
		g_shell->pipe_flag = 0;
		g_shell->op_flag = 0;
	}
}
