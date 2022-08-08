/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:29:38 by agunes            #+#    #+#             */
/*   Updated: 2022/01/20 13:29:13 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
		{
			return (NULL);
		}
		i++;
	}
	return ((char *)&s[i]);
}
/*
int	main(void)
{
	char dizi[] = "ahmet";

	printf("%s", ft_strchr(dizi, 'm'));
}
*/