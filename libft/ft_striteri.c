/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:09:26 by agunes            #+#    #+#             */
/*   Updated: 2022/01/20 15:04:45 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s != NULL)
	{	
		while (s[i] != '\0')
		{
			f(i, &s[i]);
			i++;
		}
	}
}

void	f(unsigned int a, char *b)
{
	int	i ;

	i = 0;
	if (b[i] != '\0')
	{
		b[i] = b[i + a];
		i++;
	}
}
/*
int	main(void)
{
	char dizi[] = "hakan";

	ft_striteri(dizi, f);

	printf("%s",dizi);

	
}
*/