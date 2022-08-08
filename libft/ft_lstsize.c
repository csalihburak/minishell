/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:57:40 by agunes            #+#    #+#             */
/*   Updated: 2022/01/21 14:42:03 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	r;

	r = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		r++;
	}
	return (r);
}
/*
int	main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = (t_list *)malloc(sizeof(t_list));
	b = (t_list *)malloc(sizeof(t_list));
	c = (t_list *)malloc(sizeof(t_list));
	a->next = b;
	b->next = c;
	printf("%d", ft_lstsize(a));
}
*/