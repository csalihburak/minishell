/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 12:16:05 by agunes            #+#    #+#             */
/*   Updated: 2022/01/20 13:34:11 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dest_len >= size)
	{
		return ((size + src_len));
	}
	i = 0;
	while (src[i] != '\0' && dest_len + i + 1 < size)
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	dest[i + dest_len] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[i]));
}
/*
int	main(void)
{
	char dizi[] = "ahmet";
	char dizi2[] = "hakan";

	printf("%zu", ft_strlcat(dizi, dizi2, 4));
}
*/