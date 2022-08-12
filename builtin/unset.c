/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:56:28 by agunes            #+#    #+#             */
/*   Updated: 2022/08/12 15:51:30 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	unset(void)
{
	int	i;
	int	temp;

	i = 1;
	while (g_shell->commandlist[i])
	{
		if (equalcheck(g_shell->commandlist[i]))
		{
			printf("%s\n", strerror(1));
			if (g_shell->commandlist[i + 1])
				i++;
		}
		exportsearch(g_shell->commandlist[i]);
		if (g_shell->exportflag != 0)
		{
			free(g_shell->export[g_shell->exportflag]);
			temp = g_shell->exportflag;
			while (g_shell->export[temp])
			{
				g_shell->export[temp] = g_shell->export[temp + 1];
				temp++;
			}
		}
		i++;
	}
	return (1);
}
