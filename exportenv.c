/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:46:36 by agunes            #+#    #+#             */
/*   Updated: 2022/08/26 13:36:48 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*exportedit2(char *export)
{
	int		i;
	char	*buff;

	i = 0;
	buff = NULL;
	if (!ft_strncmp(export, "SHELL=", 6))
	{
		while (g_shell->env[i])
			i++;
		free(export);
		export = ft_strdup("SHELL=");
		buff = g_shell->env[i - 1] + \
		findfirstindex(g_shell->env[i - 1], '=') + 1;
		export = ft_strjoin(export, buff);
		return (export);
	}
	return (export);
}

char	*exportedit1(char *export)
{
	char	*temp;

	temp = NULL;
	export = exportedit2(export);
	if (!ft_strncmp(export, "OLDPWD=", 7))
	{
		free(export);
		export = ft_strdup("OLDPWD");
		return (export);
	}
	else
	{
		if (equalcheck(export))
		{
			temp = export;
			export = addquote(export, 0);
			free(temp);
			return (export);
		}
	}
	return (export);
}

void	exportenvcpy(char **env)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	g_shell->env = ft_calloc(sizeof(char *), dblen(env));
	g_shell->export = ft_calloc(sizeof(char *), dblen(env));
	while (env[i])
	{
		g_shell->env[i] = ft_calloc(sizeof(char), arraylen(env[i]));
		g_shell->export[i] = ft_calloc(sizeof(char), arraylen(env[i]));
		j = 0;
		while (env[i][j])
		{
			g_shell->env[i][j] = env[i][j];
			g_shell->export[i][j] = env[i][j];
			j++;
		}
		i++;
	}
	i = -1;
	while (g_shell->export[++i])
		g_shell->export[i] = exportedit1(g_shell->export[i]);
	free(g_shell->export[i - 1]);
	g_shell->export[i - 1] = NULL;
}
