/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:06:00 by agunes            #+#    #+#             */
/*   Updated: 2022/08/13 21:35:06 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	printexport(void)
{
	int		i;

	i = 0;
	while (g_shell->export[i])
		printf("declare -x %s\n", g_shell->export[i++]);
}

int	exportequal(char *commandlist)
{
	char	*buff;

	if (commandlist[0] == '=' && commandlist[1] == '\0')
	{
		buff = ft_strdup("bash: export: `");
		buff = ft_strjoin(buff, "=");
		buff = ft_strjoin(buff, "'");
		buff = ft_strjoin(buff, ": not a valid identifier");
		write(2, buff, ft_strlen(buff));
		write(1, "\n", 1);
		free(buff);
		return (1);
	}
	if (!ft_isalpha(commandlist[0]))
	{
		buff = ft_strdup("bash: export: `");
		buff = ft_strjoin(buff, commandlist);
		buff = ft_strjoin(buff, "'");
		buff = ft_strjoin(buff, ": not a valid identifier");
		write(2, buff, ft_strlen(buff));
		write(1, "\n", 1);
		free(buff);
		return (1);
	}
	return (0);
}

int	export(void)
{
	int	i;

	i = 1;
	if (!g_shell->commandlist[1])
		printexport();
	while (g_shell->commandlist[i])
	{
		g_shell->exportflag = 0;
		if (g_shell->commandlist[i][0] != '_' && \
		!exportequal(g_shell->commandlist[i]))
		{
			if (envsearch(g_shell->commandlist[i]))
				if (equalcheck(g_shell->commandlist[i]))
					addenv(g_shell->commandlist[i]);
			if (exportsearch(g_shell->commandlist[i]))
				addexport(g_shell->commandlist[i]);
			if (!envsearch(g_shell->commandlist[i]))
				envupdate(g_shell->commandlist[i]);
		}
		i++;
	}
	return (1);
}
