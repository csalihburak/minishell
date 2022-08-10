/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:52:27 by agunes            #+#    #+#             */
/*   Updated: 2022/08/10 13:29:53 by agunes           ###   ########.fr       */
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
	i = 0;
	while (g_shell->env[i])
		i++;
	buff = ft_strrchr(g_shell->env[i - 1], '/') + 1;
	if (ft_builtinsearch(buff) == 0)
	{
		ft_path(buff);
		ft_searchfor(buff);
	}
	return (1);
}

int	ft_env(void)
{
	int	i;

	i = 0;
	while (g_shell->env[i])
		i++;
	free(g_shell->env[i - 1]);
	g_shell->env[i - 1] = ft_strdup("_=/usr/bin/env");
	i = 0;
	while (g_shell->env[i])
		printf("%s\n", g_shell->env[i++]);
	g_shell->free_flag = 0;
	return (1);
}
