/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:48:03 by scoskun           #+#    #+#             */
/*   Updated: 2022/01/13 10:54:04 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	neg = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res * neg > 2147483647)
			return (-1);
		else if (res * neg < -2147483648)
			return (0);
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return ((int)res * neg);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char a[] = "543";
	printf("%i\n",ft_atoi(a));
	printf("%i",atoi(a));

}*/
