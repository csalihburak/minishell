/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:48:17 by agunes            #+#    #+#             */
/*   Updated: 2022/08/10 11:08:12 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	dolar(char *arr)
{
	char	*a;

	a = ft_getenv(arr + 1);
	write(1, ft_getenv(arr + 1), ft_strlen(a));
}

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
		//printf("%s\n", arg[i]);
		if (arg[i][0] == '$')
			dolar(arg[i]);
		write(1, arg[i], ft_strlen(arg[i]));
		if (arg[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (g_shell->echoflag != 1)
		write(1, "\n", 1);
	return (1);
}
