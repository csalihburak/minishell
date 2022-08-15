/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdutils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:55:59 by agunes            #+#    #+#             */
/*   Updated: 2022/08/15 03:01:15 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	cdcheck(char *command)
{
	char	*buff;

	buff = ft_strdup("minishell: cd: ");
	buff = ft_strjoin(buff, command);
	buff = ft_strjoin(buff, ": ");
	if (access(command, F_OK) == -1)
	{
		buff = ft_strjoin(buff, strerror(errno));
		write(2, buff, ft_strlen(buff));
		write(1, "\n", 1);
		free(buff);
		return (0);
	}
	else if (chdir(command) == -1)
	{
		buff = ft_strjoin(buff, strerror(errno));
		write(2, buff, ft_strlen(buff));
		write(1, "\n", 1);
		free(buff);
		return (0);
	}
	free(buff);
	return (1);
}

void	notset(int status)
{
	char	*buff;

	buff = NULL;
	if (status == 1)
	{
		buff = ft_strdup("HOME NOT SET");
		write(2, buff, ft_strlen(buff));
		write(1, "\n", 1);
		free(buff);
	}
	if (status == 2)
	{
		buff = ft_strdup("minishell: cd: OLDPWD not set");
		write(2, buff, ft_strlen(buff));
		write(1, "\n", 1);
		free(buff);
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
