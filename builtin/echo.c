/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:48:17 by agunes            #+#    #+#             */
/*   Updated: 2022/08/04 11:59:29 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	flagcheck(char **arg)
{
	int	flag;

	flag = 0;
	if (arg[1] && ft_strcmp(arg[1], "-n") == 0)
		flag = 1;
	else
		flag = 0;
	if (flag == 0 && arg[1] == NULL)
	{
		printf("\n");
		return (2);
	}
	return (flag);
}

int	ft_echo(char **arg)
{
	int	i;
	int	fl;

	fl = flagcheck(arg);
	if (fl == 1)
		i = 2;
	else if (fl == 0)
		i = 1;
	else
		return (1);
	while (arg[i])
	{
		if (arg[i][0] == '\"' || arg[i][0] == '\'')
			write(1, arg[i] + 1, ft_strlen(arg[i]) - 1);
		else
			write(1, arg[i], ft_strlen(arg[i]));
		if (arg[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (fl == 0)
		write(1, "\n", 1);
	return (1);
}
