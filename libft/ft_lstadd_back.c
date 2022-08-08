/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:25:18 by agunes            #+#    #+#             */
/*   Updated: 2022/01/21 14:29:30 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		(*lst)->next = NULL;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}
/*
int	main(void)
{
	t_list	**test;
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = (t_list *)malloc(sizeof(t_list));
	b = (t_list *)malloc(sizeof(t_list));
	c = (t_list *)malloc(sizeof(t_list));
	test = &a;
	a->next = b;
	c->content = "eklendi mi?";
	ft_lstadd_back(test, c);
	printf("%s", a->next->next->content);
}
*/