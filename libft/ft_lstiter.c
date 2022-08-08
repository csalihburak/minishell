/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:11:40 by agunes            #+#    #+#             */
/*   Updated: 2022/01/22 13:50:47 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	f(void *b)
{
	char	*a;

	a = (char *)b;
	if (a == NULL)
	{
		printf("BELLEK SERBEST BIRAKILDI.");
		free(b);
	}
}
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
int main(void)
{
	t_list	*a;

	a = (t_list *)malloc(sizeof(t_list));
	ft_lstiter(a, f);
}
*/