/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 09:57:08 by scoskun           #+#    #+#             */
/*   Updated: 2022/01/05 12:00:21 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char) c)
			return ((void *)&s[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int main()
{
	char a[]= "selam";
	char b = 'l';
	printf("%s",ft_memchr(a,b,3));
}*/
