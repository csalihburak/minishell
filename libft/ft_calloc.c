/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:29:11 by agunes            #+#    #+#             */
/*   Updated: 2022/01/20 12:21:02 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	a = malloc(count * size);
	if (a == NULL)
	{
		return (NULL);
	}
	return (ft_memset(a, 0, size * count));
}
/*
int	main(void)
{
	int	a;
	int	b;

	a = 5;
	b = 2;
	ft_calloc(a, b);
}
*/