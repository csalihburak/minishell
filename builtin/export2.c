/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 10:34:25 by agunes            #+#    #+#             */
/*   Updated: 2022/08/10 10:41:24 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	eqcheck(void)
{
	int		i;
	char	**exportbuff;

	i = 0;
	if (g_shell->commandlist[1] == NULL)
	{	
		exportbuff = exportedit();
		while (exportbuff[i])
		{
			printf("%s\n", exportbuff[i]);
			free(exportbuff[i++]);
		}
		free(exportbuff);
	}
	i = 0;
	while (g_shell->commandlist[1] && g_shell->commandlist[1][i])
		if (g_shell->commandlist[1][i++] == '=')
			return (0);
	return (1);
}

char	**exportedit(void)
{
	int		i;
	int		j;
	char	*buff;
	char	**temp;

	i = -1;
	temp = malloc(sizeof(char *) * dblen2(g_shell->env));
	while (g_shell->env[++i])
		temp[i] = ft_strdup(g_shell->env[i]);
	i = -1;
	while (temp[++i])
	{
		j = -1;
		while (temp[++j])
		{
			if (temp[j][0] > temp[i][0])
			{
				buff = temp[i];
				temp[i] = temp[j];
				temp[j] = buff;
			}
		}
	}
	return (temp);
}
