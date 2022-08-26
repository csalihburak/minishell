/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:46:31 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/26 13:31:46 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*p;

	if (!s1 || !set)
		return (0);
	i = 0;
	j = ft_strlen(s1);
	k = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strchr(set, s1[j - 1]))
		j--;
	p = (char *)ft_calloc(sizeof(char), (j - i + 1));
	if (!p)
		return (0);
	while (i < j)
	{
		p[k] = s1[i];
		k++;
		i++;
	}
	p[k] = '\0';
	return (p);
}
/*
#include <stdio.h>

int main()
{
	char a[] = "Lorem ipsum sa camet";
	char b[] = "Lo re imat";
	printf("%s",ft_strtrim(a,b));
}*/
