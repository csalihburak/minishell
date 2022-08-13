/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dolar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:04:49 by agunes            #+#    #+#             */
/*   Updated: 2022/08/13 18:06:36 by agunes           ###   ########.fr       */
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

char	*cmdlistup(char *command)
{
	int		i;
	int		equal;
	char	*buff;

	i = -1;
	equal = 0;
	buff = malloc(sizeof(char) * ft_strlen((command + dolarfind(command)) + 1));
	while (command[++i] != '$')
		buff[i] = command[i];
	i = 0;
	if (!envsearch(command + dolarfind(command)))
		buff = ft_strjoin(buff, g_shell->env[g_shell->envflag] + \
		findindex(command, '='));
	else
		buff = ft_strjoin(buff, command + dolarfind(command) - 1);
	return (buff);
}

void	dolar(void)
{
	int	i;

	i = 0;
	while (g_shell->commandlist[i])
	{
		if (commandsearch(g_shell->commandlist[i], "$_"))
			printf("test\n");
		if (dolarfind(g_shell->commandlist[i]))
			g_shell->commandlist[i] = cmdlistup(g_shell->commandlist[i]);
		i++;
	}
}
