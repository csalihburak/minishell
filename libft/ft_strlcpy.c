/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:31:43 by agunes            #+#    #+#             */
/*   Updated: 2022/01/20 14:42:03 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n != 0)
	{
		while (src[i] != '\0' && (i < (n - 1)))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	char dizi[] = "ahmet";
	char dizi2[] = "hakan";

	printf("%zu", ft_strlcpy(dizi2, dizi, 6));
}
*/