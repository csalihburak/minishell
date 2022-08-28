/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:48:17 by agunes            #+#    #+#             */
/*   Updated: 2022/08/28 19:07:36 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

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

int	echo(char **commandlist)
{
	int	i;

	i = 1;
	if (echocheck(commandlist) == 0)
		return (1);
	if (g_shell->echoflag == 1)
		i++;
	while (commandlist[i])
	{
		commandlist[i] = deletechar(commandlist[i], '\'');
		write(1, commandlist[i], ft_strlen(commandlist[i]));
		if (commandlist[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (g_shell->echoflag != 1)
		write(1, "\n", 1);
	return (1);
}
