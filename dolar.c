/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dolar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:04:49 by agunes            #+#    #+#             */
/*   Updated: 2022/08/25 16:33:12 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dolar2(int i)
{
	if (!ft_strcmp(g_shell->commandlist[i], "$?"))
	{
		free(g_shell->commandlist[i]);
		g_shell->commandlist[i] = ft_itoa(g_shell->status / 256);
	}
	if (!ft_strcmp(g_shell->commandlist[i], "$_"))
	{
		g_shell->freeflag = 1;
		free(g_shell->commandlist[i]);
		g_shell->commandlist[i] = lastexe();
	}
	else if (singlequo(g_shell->commandlist[i]) && \
	dolarfind(g_shell->commandlist[i]))
		g_shell->commandlist[i] = cmdlistup(g_shell->commandlist[i]);
}

int	dolar(void)
{
	int		i;
	char	*temp;

	i = -1;
	g_shell->freeflag = 0;
	while (g_shell->commandlist[++i])
		dolar2(i);
	temp = g_shell->lastexe;
	g_shell->lastexe = ft_strdup(g_shell->commandlist[i - 1]);
	if (g_shell->freeflag != 1)
		free(temp);
	return (1);
}
