/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:06:45 by agunes            #+#    #+#             */
/*   Updated: 2022/08/26 10:53:17 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**dbl_deletechar(char **arr, int c)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		arr[i] = deletechar(arr[i], c);
		i++;
	}
	return (arr);
}

int	quote_strchr(char *arr, int c)
{
	int	i;

	i = 0;
	if (arr != NULL)
	{
		while (arr[i])
		{
			if (arr[i] == '\"')
			{
				i++;
				while (arr[i] && arr[i] != '\"')
					i++;
			}
			if (arr[i] == c)
				return (1);
			else if (arr[i] == 0)
				return (0);
			i++;
		}
	}
	return (0);
}

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

void	parser2(void)
{
	int	i;

	i = -1;
	dbfree(g_shell->commandlist);
	g_shell->commandlist = ft_split_quote(g_shell->command, '|');
	while (g_shell->commandlist[++i])
	{
		g_shell->commandlist[i] = \
		deletechar(g_shell->commandlist[i], '"');
		g_shell->pipe_flag++;
	}
}

void	parser(void)
{
	int		i;

	i = -1;
	g_shell->commandlist = ft_split_quote(g_shell->command, ' ');
	g_shell->op_flag = 0;
	g_shell->pipe_flag = 0;
	if (quote_strchr(g_shell->command, '<') || \
	quote_strchr(g_shell->command, '>'))
	{
		dbfree(g_shell->commandlist);
		g_shell->op_flag = 1;
		return ;
	}
	else if (quote_strchr(g_shell->command, '|'))
	{
		parser2();
		return ;
	}
	i = -1;
	while (g_shell->commandlist[++i])
	{
		g_shell->commandlist[i] = \
		deletechar(g_shell->commandlist[i], '"');
	}
}
