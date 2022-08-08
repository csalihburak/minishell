/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:27:28 by agunes            #+#    #+#             */
/*   Updated: 2022/01/20 12:27:05 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_len(int n)
{
	int	digit;

	digit = 0;
	if (n <= 0)
		digit++;
	while (n != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	char			*str;
	int				len;

	len = digit_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	nb = n;
	if (n < 0)
	{
		nb = -n;
		str[0] = '-';
	}
	str[len--] = '\0';
	if (nb == 0)
		str[0] = '0';
	while (len >= 0 && nb != 0)
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	return (str);
}
/*
int	main(void)
{
	int	a;

	a = 123456789;
	printf("%s", ft_itoa(a));
}
*/