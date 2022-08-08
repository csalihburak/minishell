/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:30:30 by agunes            #+#    #+#             */
/*   Updated: 2022/08/03 10:40:06 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	i = 0;
	len = ft_strlen(src);
	str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!str)
	{
		return (0);
	}
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char dizi[] = "ahmet";

	printf("%s", ft_strdup(dizi));
}
*/