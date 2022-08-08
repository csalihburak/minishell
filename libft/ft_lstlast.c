/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:03:02 by agunes            #+#    #+#             */
/*   Updated: 2022/01/21 14:34:50 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{	
		lst = lst->next;
	}
	return (lst);
}
/*
int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = (t_list *)malloc(sizeof(t_list));
	b = (t_list *)malloc(sizeof(t_list));
	a->next = b;
	b->content = "hakangunes";
	ft_lstlast(a);
	printf("%s", ft_lstlast(a)->content);
}
*/