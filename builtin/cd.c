/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:53:45 by agunes            #+#    #+#             */
/*   Updated: 2022/08/27 20:21:48 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	gohome(void)
{
	int		i;
	char	*old;
	char	*new;

	i = -1;
	while (g_shell->env[++i])
		if (!ft_strncmp(g_shell->env[i], "HOME", 4))
			break ;
	old = getcwd(NULL, 0);
	if (!chdir(g_shell->env[i] + findfirstindex(g_shell->env[i], '=') + 1))
	{
		new = getcwd(NULL, 0);
		exportpwdupdate(new, old);
		envpwdupdate(new, old);
		free(new);
	}
	else
		notset(1);
	free(old);
}

void	changedirectory(char *command)
{
	char	*old;
	char	*new;

	old = getcwd(NULL, 0);
	if (cdcheck(command))
	{
		new = getcwd(NULL, 0);
		exportpwdupdate(new, old);
		envpwdupdate(new, old);
		free(new);
	}
	free(old);
}

void	golastpwd(void)
{
	int		i;
	char	*old;
	char	*new;
	char	*temp;

	i = -1;
	old = getcwd(NULL, 0);
	while (g_shell->export[++i])
	{
		if (!ft_strcmp(g_shell->export[i], "OLDPWD"))
			notset(2);
		else if (!ft_strncmp(g_shell->export[i], "OLDPWD=", 7))
		{
			new = deletechar(g_shell->export[i], '\"');
			temp = new;
			new = ft_strdup(new + findfirstindex(new, '=') + 1);
			cdcheck(new);
			free(temp);
			exportpwdupdate(new, old);
			envpwdupdate(new, old);
			free(new);
		}
	}
	if (old != NULL)
		free(old);
}

int	cd(char *command)
{
	if (!command)
		gohome();
	else if (!ft_strcmp(command, "-"))
		golastpwd();
	else
		changedirectory(command);
	return (1);
}
