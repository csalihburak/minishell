/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:28:41 by scoskun           #+#    #+#             */
/*   Updated: 2022/01/11 10:09:31 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] != '\0') && (s2[i] == s1[i]) && (i < n - 1))
	{
		i++;
	}
	return ((unsigned char )s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h>

int main()
{
	char a[] = "sAlam ben";
	char b[] = "salam ben";
	printf("%d",ft_strncmp(a,b,3));
}*/
