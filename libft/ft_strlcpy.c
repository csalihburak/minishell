/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:27:11 by scoskun           #+#    #+#             */
/*   Updated: 2022/01/12 13:35:49 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (n != 0)
	{
		while (*src && n - 1 > 0)
		{
			*dst++ = *src++;
			n--;
		}
		*dst = 0;
	}
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{

	printf("%lu\n",ft_strlcpy((void *)0,(void *)0,10));
	//printf("%lu\n",strlcpy(a,b,16));
}*/
