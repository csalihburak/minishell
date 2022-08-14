/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:55:41 by agunes            #+#    #+#             */
/*   Updated: 2022/08/14 17:01:15 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1 && s2) && s1[i] == s2[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_prompt(void)
{
	char	*cwd;
	char	*a;

	a = getcwd(NULL, 0);
	cwd = ft_strdup("minishell / ");
	cwd = ft_strjoin(cwd, ft_strrchr(a, '/') + 1);
	cwd = ft_strjoin(cwd, " % ");
	free(a);
	return (cwd);
}

int	dblen(char **array)
{
	int	i;
	int	y;
	int	len;

	i = 0;
	y = 0;
	len = 0;
	while (array[i])
	{
		y = 0;
		while (array[i][y++])
			len++;
		i++;
		len++;
	}
	return (len);
}

int	commandsearch(char *s1, char *s2)
{
	int	i;
	int	len;
	int	s1len;
	int	s2len;

	i = 0;
	len = 0;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			len++;
		i++;
	}
	if (s1len == s2len && len == s1len && len == s2len)
		return (1);
	return (0);
}

char	*ft_getenv(char *arr)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(arr);
	while (g_shell->env[i])
	{
		if (ft_strncmp(g_shell->env[i], arr, len) == 0)
			return (ft_strchr(g_shell->env[i], '=') + 1);
		i++;
	}
	return (NULL);
}

