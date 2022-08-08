/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:19:37 by agunes            #+#    #+#             */
/*   Updated: 2022/01/20 12:37:25 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int			i;
	char		*a;
	const char	*b;

	a = (char *)dest;
	b = (const char *)src;
	i = 0;
	if (a == NULL && b == NULL)
	{
		return (NULL);
	}
	while (n > 0)
	{
		a[i] = b[i];
		i++;
		n--;
	}
	return (dest);
}
/*
int main(void)
{
	char kaynak[] = "ahmethakan";
	char hedef[] = "gunes";

	printf("%s", ft_memcpy(hedef, kaynak, 3));
}
*/