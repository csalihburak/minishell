/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:55:41 by agunes            #+#    #+#             */
/*   Updated: 2022/08/22 10:32:23 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 || s2)
	{
		while ((s1 && s2) && s1[i] == s2[i] && s2[i])
			i++;
		return (s1[i] - s2[i]);
	}
	return (0);
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

char	*deletechar(char *array, char c)
{
	int		i;
	int		x;
	int		len;
	char	*newarray;

	i = -1;
	x = 0;
	len = 0;
	while (array[++i])
	{
		if (array[i] == c)
			len++;
	}
	newarray = malloc(sizeof(char) * ft_strlen(array) - (len - 1));
	i = -1;
	while (array[++i])
	{
		if (array[i] != c)
			newarray[x++] = array[i];
	}
	newarray[x] = '\0';
	free(array);
	return (newarray);
}

int	arraylen(char *array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	dblen(char **array)
{
	int	i;
	int	y;
	int	len;

	i = 0;
	y = 0;
	len = 0;
	while (array && array[i])
	{
		y = 0;
		while (array[i][y++])
			len++;
		i++;
		len++;
	}
	return (len);
}
