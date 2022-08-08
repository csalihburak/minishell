/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:31:51 by agunes            #+#    #+#             */
/*   Updated: 2022/01/20 14:54:43 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && n > 0)
	{
		if (s1[i] != s2[i])
		{
			break ;
		}
		i++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char )s2[i]);
}
/*
int	main(void)
{
	char dizi[] = "ahmet";
	char dizi2[] = "ahmet";

	printf("%d",ft_strncmp(dizi, dizi2, 4));
}
*/