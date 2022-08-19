/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:46:36 by agunes            #+#    #+#             */
/*   Updated: 2022/08/16 18:50:11 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*exportedit4(char *export)
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

char	*exportedit3(char *export)
{
	char	*temp;

	temp = NULL;
	export = exportedit4(export);
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

void	exportedit2(char *temp, char **buff2)
{
	int	i;
	int	x;

	i = -1;
	x = -1;
	while (buff2[++i])
	{
		x = -1;
		while (buff2[++x + 1])
		{	
			if (buff2[x][0] > buff2[x + 1][0])
			{
				{
					temp = ft_strdup(buff2[x]);
					free(buff2[x]);
					buff2[x] = ft_strdup(buff2[x + 1]);
					free(buff2[x + 1]);
					buff2[x + 1] = temp;
				}
			}
		}
	}
}

char	**exportedit(char **export)
{
	char	*buff;
	char	**buff2;
	char	*temp;

	temp = NULL;
	buff = merge(export, 1);
	buff2 = ft_split(buff, ' ');
	exportedit2(temp, buff2);
	free(buff);
	return (buff2);
}

void	exportenvcpy(char **env)
{
	int		i;
	char	*buff;

	i = -1;
	buff = merge(env, 1);
	g_shell->env = ft_split(buff, ' ');
	g_shell->export = ft_split(buff, ' ');
	while (g_shell->export[++i])
		g_shell->export[i] = exportedit3(g_shell->export[i]);
	free(g_shell->export[i - 1]);
	g_shell->export[i - 1] = NULL;
	free(buff);
}
