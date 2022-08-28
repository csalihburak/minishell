/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dolarutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:10:25 by agunes            #+#    #+#             */
/*   Updated: 2022/08/28 19:04:18 by agunes           ###   ########.fr       */
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

char	*addchar(char *command)
{
	int		i;
	int		k;
	char	*arr;

	i = 2;
	k = 0;
	arr = ft_calloc(sizeof(char), (ft_strlen(command) + 3));
	arr[0] = '\'';
	arr[1] = '$';
	while (command[k])
	{
		arr[i] = command[k];
		i++;
		k++;
	}
	arr[i] = '\0';
	free(command);
	return (arr);
}

void	test(void)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (g_shell->buff[i])
	{
		if (ft_strchr(g_shell->buff[i], '\"'))
		{	
			g_shell->buff[i] = deletechar(g_shell->buff[i], '\"');
			g_shell->buff[i] = deletechar(g_shell->buff[i], '\'');
		}
		if (!ft_strchr(g_shell->buff[i], '\"') && \
		ft_strchr(g_shell->buff[i], '\''))
			g_shell->buff[i] = addchar(g_shell->buff[i]);
		i++;
	}
}
