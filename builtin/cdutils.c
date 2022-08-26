/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdutils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:55:59 by agunes            #+#    #+#             */
/*   Updated: 2022/08/26 12:19:26 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	cdcheck(char *command)
{
	if (access(command, F_OK) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(command, 2);
		ft_putstr_fd(":", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 1);
		return (0);
	}
	else if (chdir(command) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(command, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 1);
		return (0);
	}
	return (1);
}

void	notset(int status)
{
	if (status == 1)
	{
		ft_putstr_fd("HOME NOT SET", 2);
		ft_putstr_fd("\n", 1);
	}
	if (status == 2)
	{
		ft_putstr_fd("minishell: cd: OLDPWD not set", 2);
		ft_putstr_fd("\n", 1);
	}
}

void	exportpwdupdate(char *new, char *old)
{
	int		i;
	char	*buff;

	i = -1;
	while (g_shell->export[++i])
	{
		if (!ft_strncmp(g_shell->export[i], "PWD=", 4))
		{
			buff = ft_strdup("PWD=");
			buff = ft_strjoin(buff, new);
			buff = addquote(buff, 1);
			free(g_shell->export[i]);
			g_shell->export[i] = ft_strdup(buff);
			free(buff);
		}
		else if (!ft_strncmp(g_shell->export[i], "OLDPWD", 6))
		{
			buff = ft_strdup("OLDPWD=");
			buff = ft_strjoin(buff, old);
			buff = addquote(buff, 1);
			free(g_shell->export[i]);
			g_shell->export[i] = ft_strdup(buff);
			free(buff);
		}
	}
}

void	envpwdupdate(char *new, char *old)
{
	int		i;
	char	*buff;

	i = -1;
	while (g_shell->env[++i])
	{
		if (!ft_strncmp(g_shell->env[i], "PWD=", 4))
		{
			buff = ft_strdup("PWD=");
			buff = ft_strjoin(buff, new);
			free(g_shell->env[i]);
			g_shell->env[i] = ft_strdup(buff);
			free(buff);
		}
		else if (!ft_strncmp(g_shell->env[i], "OLDPWD", 6))
		{
			buff = ft_strdup("OLDPWD=");
			buff = ft_strjoin(buff, old);
			free(g_shell->env[i]);
			g_shell->env[i] = ft_strdup(buff);
			free(buff);
		}
	}
}
