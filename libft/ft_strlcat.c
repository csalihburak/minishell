/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:25:32 by scoskun           #+#    #+#             */
/*   Updated: 2022/01/06 11:24:32 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	if (n <= (size_t)ft_strlen(dst))
		return (n + ft_strlen(src));
	i = ft_strlen(dst);
	j = 0;
	while ((i + 1 < n) && (src[j] != '\0'))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[j]));
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char a[] = "salih";
	char b[] = "Coskun";

	printf("%lu\n",strlcat(a,b,6));
	//printf("%lu",ft_strlcat(a,b,12));
	printf("%s",a);
}*/
