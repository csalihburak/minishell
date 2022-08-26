/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:56:24 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/26 13:31:51 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char	const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	s_len;
	size_t	end;

	if (!s)
		return (NULL);
	end = 0;
	s_len = ft_strlen(s);
	if (start < s_len)
		end = s_len - start;
	if (end > len)
		end = len;
	dest = (char *)ft_calloc(sizeof(char), end + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s + start, end + 1);
	return (dest);
}
/*
#include <stdio.h>
int main(void)
{
    char dizi[] = "lorem ipsum dolor sit amet";
    printf("%s",ft_substr(dizi,7,10));
}*/
