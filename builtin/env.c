/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:52:27 by agunes            #+#    #+#             */
/*   Updated: 2022/08/10 16:07:37 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	envexecupdate(char *arr)
{
	int		i;

	i = 0;
	while (g_shell->env[i])
		i++;
	free(g_shell->env[i - 1]);
	g_shell->env[i - 1] = ft_strdup("_=");
	g_shell->env[i - 1] = ft_strjoin(g_shell->env[i - 1], arr);
	return (1);
}

int	runlastexec(void)
{
	char	*buff;
	int		i;

	i = 0;
	ft_builtfree();
	i = 0;
	while (g_shell->env[i])
		i++;
	buff = ft_strrchr(g_shell->env[i - 1], '/');
	if (ft_builtinsearch(buff + 1) == 0)
	{
		ft_path(buff + 1);
		ft_searchfor(buff + 1);
		g_shell->free_flag = 1;
	}
	i = 0;
	return (1);
}

int	ft_env(void)
{
	int	i;

	i = 0;
	ft_builtfree();
 	while (g_shell->env[i])
		i++;
	free(g_shell->env[i - 1]);
	g_shell->env[i - 1] = ft_strdup("_=/usr/bin/env");
	i = 0;
	while (g_shell->env[i])
		printf("%s\n", g_shell->env[i++]);
	return (1);
}
