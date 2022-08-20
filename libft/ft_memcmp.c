/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 09:58:40 by scoskun           #+#    #+#             */
/*   Updated: 2022/01/12 13:50:54 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	size_t	x;

	x = 0;
	while (x < len)
	{
		if (((unsigned char *)s1)[x] != (((unsigned char *)s2)[x]))
			return (((unsigned char *)s1)[x] - (((unsigned char *)s2)[x]));
		x++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char a[] = "selAm";
	char b[] = "selam";
	printf("%d\n", ft_memcmp(a,b,3));
	printf("%d\n", memcmp(a,b,3));
}
*/
