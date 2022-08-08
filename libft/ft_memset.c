/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:29:20 by agunes            #+#    #+#             */
/*   Updated: 2022/01/20 12:48:12 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;

	i = 0;
	a = (unsigned char *)s;
	while (i < n)
	{
		a[i] = c;
		i++;
	}
	return (s);
}
/*
int main(void)
{
	char dizi [] = "ahmet";

	printf("%s", ft_memset(dizi, 'h', 4));
}
*/
