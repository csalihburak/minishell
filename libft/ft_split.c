/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:22:09 by agunes            #+#    #+#             */
/*   Updated: 2022/08/04 12:39:26 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	yenidizisayi(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*kopyala(char *array, const char *s, int i, int len)
{
	int	j;

	j = 0;
	while (len > 0)
	{
		array[j] = s[i - len];
		len--;
		j++;
	}
	array[j] = '\0';
	return (array);
}

static void	*splitit(char **array, char const *s, char c, int mallocsayi)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (j < mallocsayi)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
			len++;
		}
		array[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (!array[j])
			return (NULL);
		kopyala(array[j], s, i, len);
		j++;
		len = 0;
	}
	array[j] = NULL;
	return (array[j]);
}

char	**ft_split(char *s, char c)
{
	int		mallocsayi;
	char	**array;

	if (s != NULL)
	{
		mallocsayi = yenidizisayi(s, c);
		array = (char **)malloc(sizeof(char *) * (mallocsayi + 1));
		if (!array)
			return (NULL);
		splitit(array, s, c, mallocsayi);
		return (array);
	}
	return (0);
}
