/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:25:49 by agunes            #+#    #+#             */
/*   Updated: 2022/08/25 12:33:58 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

char	*editcommand(char *command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		command[i] = ft_tolower(command[i]);
		i++;
	}
	return (command);
}

int	builtinsearch(char *command)
{
	command = editcommand(command);
	if (g_shell->builtflag == 1)
	{
		g_shell->path = g_shell->program->path;
		g_shell->commandlist = g_shell->program->command;
	}
	if (!ft_strcmp(command, "$?"))
	{
		free(command);
		command = ft_itoa(g_shell->status / 256);
		return (0);
	}
	if (!ft_strcmp(command, "env"))
		return (env());
	if (!ft_strcmp(command, "cd"))
		return (cd(g_shell->commandlist[1]));
	if (!ft_strcmp(command, "echo"))
		return (echo(g_shell->commandlist));
	if (!ft_strcmp(command, "pwd"))
		return (pwd());
	if (!ft_strcmp(command, "exit"))
		exit(1);
	if (!ft_strcmp(command, "export"))
		return (export());
	if (!ft_strcmp(command, "unset"))
		return (unset());
	return (0);
}
