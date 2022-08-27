/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 20:09:17 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/27 12:47:00 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ca;

	ca = malloc(count * size);
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
