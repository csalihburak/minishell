/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:53:45 by agunes            #+#    #+#             */
/*   Updated: 2022/08/11 14:26:24 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

char	*ft_getenv(char *arr)
{
	int	i;

	i = 0;
	while (g_shell->env[i])
	{
		if (ft_strncmp(g_shell->env[i], arr, ft_strlen(arr)) == 0)
		{
			return (ft_strchr(g_shell->env[i], '=') + 1);
		}
		i++;
	}
	return (NULL);
}

int	ft_cd(char *command)
{
	char	*old;
	char	*new;

	if (!command)
	{
		old = getcwd(NULL, 0);
		chdir(ft_getenv("HOME"));
		new = getcwd(NULL, 0);
		envpwdupdate(new, old);
	}
	else
	{
		if (access(command, F_OK) == -1)
		{
			printf("cd: no such file or directory: %s\n", command);
			return (1);
		}
		old = getcwd(NULL, 0);
		if (chdir(command) == -1)
			printf("cd: permission denied: %s\n", command);
		new = getcwd(NULL, 0);
		envpwdupdate(new, old);
	}
	return (1);
}

void	envpwdupdate(char *new, char *old)
{
	int		i;

	i = 0;
	while (g_shell->env[i])
	{
		if (!ft_strncmp(g_shell->env[i], "PWD", 3))
		{
			free(g_shell->env[i]);
			g_shell->env[i] = ft_strdup("PWD=");
			g_shell->env[i] = ft_strjoin(g_shell->env[i], new);
		}
		if (!ft_strncmp(g_shell->env[i], "OLDPWD", 5))
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
