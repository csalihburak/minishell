/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:07:10 by agunes            #+#    #+#             */
/*   Updated: 2022/08/04 16:15:24 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**spltnorm(char *command, int i, int k, int j)
{
	char	**cmd;

	cmd = malloc(sizeof(char *) * 10);
	while (command[++i])
	{
		j = 0;
		if (command[i] != '"' && command[i] != ' ')
		{
			cmd[k] = malloc(sizeof(char) * 1000);
			while (command[i] && command[i] != '"' && command[i] != ' ')
				cmd[k][j++] = command[i++];
			cmd[k++][j] = '\0';
		}
		if (command[i] == '"')
		{
			i++;
			cmd[k] = malloc(sizeof(char) * 1000);
			j = 0;
			while (command[i] && command[i] != '"')
				cmd[k][j++] = command[i++];
			cmd[k++][j] = '\0';
		}
	}
	cmd[k] = NULL;
	return (cmd);
}

char	**splt2norm(char *command, int i, int k, int j)
{
	char	**cmd;

	cmd = malloc(sizeof(char *) * 16);
	while (command[i])
	{
		j = 0;
		if ((command[i] != '>' && command[i] != '<') && command[i] != ' ')
		{
			cmd[k] = malloc(sizeof(char) * 1000);
			while (command[i] && command[i] != ' ' && (command[i] != '>' && \
			command[i] != '<'))
				cmd[k][j++] = command[i++];
			cmd[k++][j] = '\0';
		}
		if (command[i] == '>' || command[i] == '<')
		{
			j = 0;
			cmd[k] = malloc(sizeof(char) * 100);
			cmd[k][j++] = command[i];
			cmd[k++][j] = '\0';
		}
		i++;
	}
	cmd[k] = NULL;
	return (cmd);
}
