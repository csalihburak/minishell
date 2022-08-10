/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:31:16 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/10 11:19:23 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_builtinsearch_pipe(char *arr)
{
	g_shell->path = g_shell->program->path;
	g_shell->commandlist = g_shell->program->command;
	if (!ft_strncmp(arr, "$_", 2))
		return (runlastexec());
	if (!ft_strncmp(arr, "$", 1))
		return (ft_envexe());
	if (!ft_strcmp(arr, "env"))
		return (ft_env());
	if (!ft_strcmp(arr, "cd"))
		return (ft_cd(g_shell->program->command[1]));
	if (!ft_strcmp(arr, "echo"))
		return (ft_echo(g_shell->program->command));
	if (!ft_strcmp(arr, "pwd"))
		return (ft_pwd());
	if (!ft_strcmp(arr, "exit"))
		ft_exit();
	if (!ft_strcmp(arr, "export"))
		return (ft_export());
	if (!ft_strcmp(arr, "unset"))
		return (ft_unset());
	return (0);
}
