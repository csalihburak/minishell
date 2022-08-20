/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:00:57 by scoskun           #+#    #+#             */
/*   Updated: 2022/01/04 10:02:16 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*src_t;
	char		*dest_t;
	int			i;

	i = 0;
	src_t = (char *)src;
	dest_t = (char *)dest;
	if (!dest_t && !src_t)
		return (0);
	while (n > 0)
	{
		dest_t[i] = src_t[i];
		i++;
		n--;
	}
	return (dest_t);
}
/*
#include <stdio.h>

int main()
{
	char cp[] = "Bilgisayar&Proglamlama";
	char dest[] = "Selam Ben Burak";
	printf("%s",ft_memcpy(dest, cp, 10));
}
*/
