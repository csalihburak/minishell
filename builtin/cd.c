/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:53:45 by agunes            #+#    #+#             */
/*   Updated: 2022/08/14 18:16:56 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	cdcheck(char *command, char *old)
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
		free(old);
		free(buff);
		return (0);
	}
	else if (chdir(command) == -1)
	{
		buff = ft_strjoin(buff, strerror(errno));
		write(2, buff, ft_strlen(buff));
		write(1, "\n", 1);
		free(old);
		free(buff);
		return (0);
	}
	free(buff);
	return (1);
}

void	notset(char *old)
{
	char	*buff;

	buff = ft_strdup("HOME NOT SET");
	write(2, buff, ft_strlen(buff));
	write(1, "\n", 1);
	free(old);
	free(buff);
}

void	exportpwdupdate(char *new, char *old)
{
	int		i;
	char	*buff;

	i = 0;
	buff = NULL;
	while (g_shell->export[i])
	{
		if (!ft_strncmp(g_shell->export[i], "PWD=", 4))
		{
			free(g_shell->export[i]);
			g_shell->export[i] = ft_strdup("PWD=");
			g_shell->export[i] = ft_strjoin(g_shell->export[i], new);
		}
		if (!ft_strncmp(g_shell->export[i], "OLDPWD", 5))
		{
			free(g_shell->export[i]);
			g_shell->export[i] = ft_strdup("OLDPWD=");
			g_shell->export[i] = ft_strjoin(g_shell->export[i], old);
			buff = g_shell->export[i];
			g_shell->export[i] = addquote(g_shell->export[i]);
			free(buff);
		}
		i++;
	}
}

void	pwdupdate(char *new, char *old)
{
	int		i;

	i = 0;
	while (g_shell->env[i])
	{
		exportpwdupdate(new, old);
		if (!ft_strncmp(g_shell->env[i], "PWD=", 4))
		{
			free(g_shell->env[i]);
			g_shell->env[i] = ft_strdup("PWD=");
			g_shell->env[i] = ft_strjoin(g_shell->env[i], new);
		}
		if (!ft_strncmp(g_shell->env[i], "OLDPWD=", 6))
		{
			free(g_shell->env[i]);
			g_shell->env[i] = ft_strdup("OLDPWD=");
			g_shell->env[i] = ft_strjoin(g_shell->env[i], old);
		}
		i++;
	}
	free(new);
	free(old);
}

int	ft_cd(char *command)
{
	char	*old;
	char	*new;

	if (!command)
	{
		old = getcwd(NULL, 0);
		if (chdir(ft_getenv("HOME")) == 0)
		{
			new = getcwd(NULL, 0);
			pwdupdate(new, old);
		}
		else
			notset(old);
	}
	else
	{
		old = getcwd(NULL, 0);
		if (cdcheck(command, old))
		{
			new = getcwd(NULL, 0);
			pwdupdate(new, old);
		}
	}
	return (1);
}

