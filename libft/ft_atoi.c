/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:25:22 by agunes            #+#    #+#             */
/*   Updated: 2022/01/19 16:43:06 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	long int	sayi;
	int			isaret;

	i = 0;
	sayi = 0;
	isaret = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			isaret = isaret * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sayi = (sayi * 10) + str[i] - '0';
		i++;
		if (sayi * isaret > 2147483647)
			return (-1);
		if (sayi * isaret < -2147483648)
			return (0);
	}
	return (sayi * isaret);
}
/*
int main()
{
    char a[] = "\n\t\n\t\n\t-+5234AAAgreghrtsdasd";
    printf("%d\n",ft_atoi(a));
}*/
