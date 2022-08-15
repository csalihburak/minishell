/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:25:49 by agunes            #+#    #+#             */
/*   Updated: 2022/08/14 19:54:41 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_builtinsearch(char *arr)
{
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
		return (export());
	if (!ft_strcmp(arr, "unset"))
		return (unset());
	return (0);
}
