/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:08:10 by agunes            #+#    #+#             */
/*   Updated: 2022/08/25 17:59:23 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	exitfunc(void)
{
	int	i;

	i = 0;
	if (g_shell->commandlist[1] != NULL)
	{
		while (g_shell->commandlist[i])
		{
			if (!ft_isdigit(g_shell->commandlist[1][i]))
			{
				printf("exit\n");
				ft_putstr_fd("minishell: exit: ", 2);
				ft_putstr_fd(g_shell->commandlist[1], 2);
				ft_putstr_fd(": numeric argument required\n", 2);
				exit(255);
			}
			i++;
		}
		exit(ft_atoi(g_shell->commandlist[1]) % 256);
	}
	else
		exit(0);
}
