/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:48:17 by agunes            #+#    #+#             */
/*   Updated: 2022/08/13 14:27:30 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	onedolar(char *command)
{
	int	i;

	i = 0;
	command = 0;
	return )(1;
}

int	dolar(char *command)
{
	int		i;
	int		len;
	int		len2;

	i = 0;
	if (ft_strncmp(command, "$", 1) && command[1] == '\0')
	{
		if (onedolar(command))
			return (1);
	}
	else
	{
		while (g_shell->env[i])
				i++;
		len = ft_strlen(ft_strrchr(g_shell->env[i - 1], '/') - 1);
		len2 = ft_strlen(ft_strrchr(g_shell->env[i - 1], '/'));
		if (!ft_strncmp(command, "$_", 2) && command[2] == '\0')
		{	
			if ((ft_strrchr(g_shell->env[i - 1], '/') - 1)[0] == '.')
				write(1, ft_strrchr(g_shell->env[i - 1], '/') - 1, len);
			else
				write(1, ft_strrchr(g_shell->env[i - 1], '/'), len2);
			return (1);
		}
	}
	return (0);
}

int	echocheck(char **commandlist)
{
	g_shell->echoflag = 0;
	if (commandlist[1] == NULL)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (!ft_strncmp(commandlist[1], "-n", 2))
		if (commandlist[1][2] == '\0')
			g_shell->echoflag = 1;
	return (1);
}

int	ft_echo(char **commandlist)
{
	int	i;

	i = 1;
	if (echocheck(commandlist) == 0)
		return (1);
	if (g_shell->echoflag == 1)
		i++;
	while (commandlist[i])
	{
		if (dolar(commandlist[i]))
		{
			if (commandlist[i + 1])
			{
				write(1, " ", 1);
				i++;
			}
		}
		write(1, commandlist[i], ft_strlen(commandlist[i]));
		if (commandlist[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (g_shell->echoflag != 1)
		write(1, "\n", 1);
	return (1);
}
