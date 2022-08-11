/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:48:17 by agunes            #+#    #+#             */
/*   Updated: 2022/08/11 11:45:18 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_echo(char **arg)
{
	int	i;

	i = 1;
	if (!ft_strcmp(arg[1], "-n"))
	{
		g_shell->echoflag = 1;
		i = 2;
	}
	while (arg[i])
	{
		write(1, arg[i], ft_strlen(arg[i]));
		if (arg[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (g_shell->echoflag != 1)
		write(1, "\n", 1);
	return (1);
}
