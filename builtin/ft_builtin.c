/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:25:49 by agunes            #+#    #+#             */
/*   Updated: 2022/08/10 14:09:59 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_builtinsearch(char *arr)
{
	if (!ft_strncmp(arr, "$_", 2))
		return (runlastexec());
	if (!ft_strncmp(arr, "$", 1))
		return (ft_envexe());
	if (!ft_strcmp(arr, "env"))
		return (ft_env());
	if (!ft_strcmp(arr, "cd"))
		return (ft_cd(g_shell->commandlist[1]));
	if (!ft_strcmp(arr, "echo"))
		return (ft_echo(g_shell->commandlist));
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
