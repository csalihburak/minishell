/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:42:19 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/26 13:35:25 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	howmany(const char *s, char c)
{
	int	i;
	int	count ;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*print_it(char *p, const char *s, int i, int k)
{
	int	x;

	x = 0;
	while (k > 0)
	{
		p[x] = s[i - k];
		x++;
		k--;
	}
	p[x] = '\0';
	return (p);
}

static char	*word_split(char **p, const char *s, char c, int howmny)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (j < howmny)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
			k++;
		}
		p[j] = (char *)ft_calloc(sizeof(char), (k + 1));
		if (!p)
			return (0);
		print_it(p[j], s, i, k);
		j++;
		k = 0;
	}
	p[j] = 0;
	return (p[j]);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		howmny;

	if (s)
	{
		howmny = howmany(s, c);
		p = (char **)ft_calloc(sizeof(char *), (howmny + 1));
		if (!p)
			return (0);
		word_split(p, s, c, howmny);
		return (p);
	}
	return (0);
}
/*
#include <stdio.h>

int main()
{
	char *a = "Salih Burak Coskun Eyup Guler";
	char b = 'u';
	char **c;
	int i;

	i = 0;
	c = ft_split(a,b);

	while(i <= 2)
	{	
		printf("%s\n",c[i]);
		i++;
	}
}*/
