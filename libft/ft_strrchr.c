/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:29:32 by scoskun           #+#    #+#             */
/*   Updated: 2022/01/08 11:14:24 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == ((char) c))
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}
/*
#include <stdio.h>
int main ()
{
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = 'i';
   char *ret;

   ret = ft_strrchr(str, ch);

   printf("String after |%c| is - |%s|\n", ch, ret);

   return(0);
}*/
