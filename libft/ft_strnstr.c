/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:31:02 by scoskun           #+#    #+#             */
/*   Updated: 2022/01/11 10:39:38 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	int		len;

	if (!*little)
		return ((char *)big);
	len = ft_strlen(little);
	while ((*big) && n-- >= (size_t)len)
	{
		i = 0;
		while ((big[i] == little[i]))
		{
			i++;
			if (little[i] == '\0')
				return ((char *)(big));
		}
		big++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char a[] = "a";
	printf("%s\n",ft_strnstr(a,a,2));
	printf("%s",strnstr(a,a,12));
}*/
