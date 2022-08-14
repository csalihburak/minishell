/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:53:45 by agunes            #+#    #+#             */
/*   Updated: 2022/08/14 20:28:23 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	gohome(void)
{
	char	*old;
	char	*new;

	old = getcwd(NULL, 0);
	if (chdir(ft_getenv("HOME")) == 0)
	{
		new = getcwd(NULL, 0);
		pwdupdate(new, old);
	}
	else
		notset(old);
}

void	changedirectory(char *command)
{
	char	*old;
	char	*new;

	old = getcwd(NULL, 0);
	if (cdcheck(command, old))
	{
		new = getcwd(NULL, 0);
		pwdupdate(new, old);
	}
}

void	golastpwd(void)
{
	int		i;
	char	*old;
	char	*new;
	char	*oldpwd;

	i = 0;
	old = 0;
	new = 0;
	oldpwd = 0;
	while (g_shell->export[i])
	{
		if (!ft_strcmp(g_shell->export[i], "OLDPWD"))
			printf("test\n");
		i++;
	}
	old = getcwd(NULL, 0);
}

int	ft_cd(char *command)
{
	if (!command)
		gohome();
	if (!ft_strcmp(command, "-"))
		golastpwd();
	else
		changedirectory(command);
	return (1);
}

