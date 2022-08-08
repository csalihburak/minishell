/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:13:55 by agunes            #+#    #+#             */
/*   Updated: 2022/01/20 12:30:26 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	char	*s1;

	i = 0;
	s1 = (char *)str;
	while (i < n)
	{
		if (s1[i] == c)
		{
			return (&s1[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char dizi[] = "deneme123";

	printf("%s", ft_memchr(dizi, 'e', (size_t) 4));
}
*/