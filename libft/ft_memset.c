/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:23:12 by scoskun           #+#    #+#             */
/*   Updated: 2022/01/04 16:24:33 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*src;
	int		i;

	i = 0;
	src = (char *) s;
	while (n > 0)
	{
		src[i] = c;
		i++;
		n--;
	}
	return (src);
}
/*
int main()
{
	char a[] = "Selam ben burak";

	printf("%s",ft_memset(a, 'x', 12));
}
*/
