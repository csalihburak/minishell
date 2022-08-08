/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:27:13 by agunes            #+#    #+#             */
/*   Updated: 2022/01/20 12:19:26 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*a;

	a = (char *)s;
	i = 0;
	while (n > 0)
	{
		a[i] = 0;
		i++;
		n--;
	}
}
/*
int main(void)
{
	int	i;

	i = 0;
	char dizi[] = "123456";
	ft_bzero(dizi,4);
	while (dizi[i] <= '6')
	{
		write(1, &dizi[i], 1);
		i++;
	}
}
*/