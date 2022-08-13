/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:55:41 by agunes            #+#    #+#             */
/*   Updated: 2022/08/13 18:07:52 by agunes           ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		a;
	char	*array;
	size_t	len;

	a = 0;
	i = 0;
	if (s1 != NULL)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
		array = (char *)malloc(sizeof(char) * (len));
		if (!array)
			return (0);
		if (array == NULL)
			return (0);
		while (s1[i] != '\0')
			array[a++] = s1[i++];
		i = 0;
		while (s2[i] != '\0')
			array[a++] = s2[i++];
		array[a] = '\0';
		free(s1);
		return (array);
	}
	return (0);
}

char	*ft_prompt(void)
{
	char	*cwd;
	char	*a;

	a = getcwd(NULL, 0);
	cwd = ft_strdup("\033[0;36mminishell / ");
	cwd = ft_strjoin(cwd, ft_strrchr(a, '/') + 1);
	cwd = ft_strjoin(cwd, " \n★ \033[0;35m");
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
