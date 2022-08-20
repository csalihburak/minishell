/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:15:12 by scoskun           #+#    #+#             */
/*   Updated: 2022/01/12 14:19:45 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	n2;
	char	a;

	n2 = n;
	if (n2 < 0)
	{
		write(fd, "-", 1);
		n2 *= -1;
	}
	if (n2 >= 0 && n2 <= 9)
	{
		a = n2 + 48;
		write(fd, &a, 1);
		return ;
	}
	else
		ft_putnbr_fd(n2 / 10, fd);
	ft_putnbr_fd(n2 % 10, fd);
}
/*
int main()
{
	ft_putnbr_fd(256223,1);
}*/
