/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:34:10 by agunes            #+#    #+#             */
/*   Updated: 2022/01/20 17:03:22 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*array;

	i = 0;
	if (s != NULL)
	{
		array = (char *)malloc(sizeof(char) * (len + 1));
		if (array == NULL)
		{
			return (NULL);
		}
		while (start < ft_strlen(s) && i < len)
		{
			array[i] = s[start];
			i++;
			start++;
		}
		array[i] = '\0';
		return (array);
	}
	return (0);
}
/*
int main(void)
{
	char dizi[] = "ahmethakan";

	printf("%s", ft_substr(dizi, 0, 9));
}
*/