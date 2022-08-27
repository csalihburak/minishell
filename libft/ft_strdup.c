/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:42:46 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/27 12:47:17 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*new;
	size_t	i;

	i = 0;
	len = ft_strlen(s1) + 1;
	new = (char *) ft_calloc(sizeof(char), len);
	if (!new)
		return (0);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
/*
#include <stdio.h>

int main()
{
	char a[] = "seawdwadawdlan";
	char *b = ft_strdup(a);

	printf("%s",b);
}*/
