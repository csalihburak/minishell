/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 20:09:17 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/26 13:30:14 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ca;

	ca = ft_calloc(count * size);
	if (ca == 0)
		return (ca);
	ft_bzero(ca, count * size);
	return (ca);
}
/*
#include <stdio.h>
int main()
{
	void	*deneme;
	deneme = ft_calloc(5,5);
	printf("%s",deneme);

}*/
