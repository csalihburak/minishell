/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:00:33 by agunes            #+#    #+#             */
/*   Updated: 2022/08/11 14:57:00 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	exportupdate(char *commandlist)
{
	char	*buff;
	char	*temp;

	buff = merge(g_shell->export);
	buff = ft_strjoin(buff, " ");
	if (equalcheck(commandlist) == 1)
	{
		temp = addquote(commandlist);
		buff = ft_strjoin(buff, temp);
		free(temp);
		buff = ft_strjoin(buff, "\"");
	}
	else if (!ft_getenv(commandlist))
		buff = ft_strjoin(buff, commandlist);
	g_shell->export = ft_split(buff, ' ');
	free(buff);
}

void	envupdate(char *commandlist)
{
	char	*buff;

	buff = merge(g_shell->env);
	buff = ft_strjoin(buff, " ");
	buff = ft_strjoin(buff, commandlist);
	g_shell->env = ft_split(buff, ' ');
	free(buff);
}

int	ft_export(void)
{
	int	i;

	i = 1;
	while (g_shell->commandlist[i])
	{
		if (envsearch(g_shell->commandlist[i]))
			if (equalcheck(g_shell->commandlist[i]))
				envupdate(g_shell->commandlist[i]);
		if (exportsearch(g_shell->commandlist[i]))
			exportupdate(g_shell->commandlist[i]);
		i++;
	}
	return (1);
}
