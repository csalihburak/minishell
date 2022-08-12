/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:48:17 by agunes            #+#    #+#             */
/*   Updated: 2022/08/12 21:02:42 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	dolar(char *command)
{
	if (!ft_strncmp(command, "$_", 2) && command[3] == '\0')
		printf("test\n");
}

int	ft_echo(char **commandlist)
{
	int	i;

	i = 1;
	if (!ft_strcmp(commandlist[1], "-n"))
	{
		g_shell->echoflag = 1;
		i = 2;
	}
	while (commandlist[i])
	{
		dolar(commandlist[i]);
	}
	if (g_shell->echoflag != 1)
		write(1, "\n", 1);
	return (1);
}
