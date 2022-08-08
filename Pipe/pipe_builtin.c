/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:31:16 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/08 10:53:56 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_builtinsearch_pipe(t_token *program)
{
	if (!ft_strcmp(program->command[0], "env"))
		return (ft_env());
	if (!ft_strcmp(program->command[0], "cd"))
		return (ft_cd(program->command[1]));
	if (!ft_strcmp(program->command[0], "echo"))
		return (ft_echo(program->command));
	if (!ft_strcmp(program->command[0], "pwd"))
		return (ft_pwd());
	if (!ft_strcmp(program->command[0], "exit"))
		ft_exit();
	if (!ft_strcmp(program->command[0], "export"))
		return (ft_export());
/* 	if (ft_strcmp(program->command[0], "unset"))
		ft_unset(program->command, g_shell->env); */
	return (0);
}
