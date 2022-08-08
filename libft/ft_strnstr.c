/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:41:27 by agunes            #+#    #+#             */
/*   Updated: 2022/01/20 15:16:05 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *dst, size_t len)
{
	size_t	i;
	int		b;

	i = 0;
	b = 0;
	if (dst[i] == '\0')
	{
		return ((char *)src);
	}	
	while (src[i] && i < len)
	{
		b = 0;
		while (dst[b] && src[i + b] == dst[b] && i + b < len)
		{
			b++;
		}
		if (dst[b] == '\0')
		{
			return ((char *)(src + i));
		}
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
	char kaynak[] = "ahmet";
	char hedef[] = "ahmet";

	printf("%s", ft_strnstr(kaynak, hedef, 3));
}
*/