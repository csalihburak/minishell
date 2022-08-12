/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:06:00 by agunes            #+#    #+#             */
/*   Updated: 2022/08/12 13:00:25 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	printexport(void)
{
	int		i;

	i = 0;
	while (g_shell->export[i])
		printf("%s\n", g_shell->export[i++]);
}

int	export(void)
{
	int	i;

	i = 1;
	if (g_shell->commandlist[1] == NULL)
		printexport();
	while (g_shell->commandlist[i])
	{
		g_shell->exportflag = 0;
		g_shell->unsetflag = 0;
		if (envsearch(g_shell->commandlist[i]))
			if (equalcheck(g_shell->commandlist[i]))
				addenv(g_shell->commandlist[i]);
		if (exportsearch(g_shell->commandlist[i]))
			addexport(g_shell->commandlist[i]);
		if (!envsearch(g_shell->commandlist[i]))
			envupdate(g_shell->commandlist[i]);
		i++;
	}
	return (1);
}
