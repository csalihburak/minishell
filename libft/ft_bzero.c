/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 09:49:42 by scoskun           #+#    #+#             */
/*   Updated: 2022/01/04 21:03:16 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*src;
	int		i;

	i = 0;
	src = (char *)s;
	while (n > 0)
	{
		src[i] = 0;
		i++;
		n--;
	}
}
/*
int main()
{
	char a[] = "selam ben Burak";
	ft_bzero(a, 5);
	int j;
	for (j = 0; j < 15;j++)
		printf("%c", a[j]);
}*/
