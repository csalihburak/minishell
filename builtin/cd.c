/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:53:45 by agunes            #+#    #+#             */
/*   Updated: 2022/08/28 13:49:55 by agunes           ###   ########.fr       */
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

int	cd(char *command)
{
	if (!command)
		gohome();
	else
		changedirectory(command);
	return (1);
}
