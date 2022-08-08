/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:51:59 by agunes            #+#    #+#             */
/*   Updated: 2022/01/20 14:52:34 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*array;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	array = (char *)malloc(ft_strlen(s) + 1);
	if (array == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		array[i] = f(i, s[i]);
		i++;
	}
	array[i] = '\0';
	return (array);
}
/*
char	f(unsigned int a, char b)
{
	return (b + a);
}

int	main(void)
{
	char dizi[] = "ahmet1";

	char *test;

	test = ft_strmapi(dizi, f);
	printf("%s",test);
}
*/