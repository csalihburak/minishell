/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:36:44 by agunes            #+#    #+#             */
/*   Updated: 2022/01/21 18:19:29 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list	**liste;
	t_list	*ilk;
	t_list	*iki;
	t_list	*yeni;
	t_list	*yapistir;
	t_list	*back;

	liste = (t_list **)malloc(sizeof(t_list));
	ilk = (t_list *)malloc(sizeof(t_list));
	iki = (t_list *)malloc(sizeof(t_list));
	yeni = (t_list *)malloc(sizeof(t_list));
	yapistir = (t_list *)malloc(sizeof(t_list));
	back = (t_list *)malloc(sizeof(t_list));
	liste = &ilk;
	ilk->next = iki;
	iki->next = yeni;
	yeni->next = yapistir;
	yapistir->next = back;
	back->next = NULL;
	ilk->content = "eyup";
	iki->content = "malasaha";
	yeni->content = "agunes";
	yapistir->content = "seyildiz";
	back->content = "burakdasilva";
	while ((*liste)->next != NULL)
	{
		(*liste) = (*liste)->next;
	}	
	printf("%s", (*liste)->content);
	printf("------------\n");
	printf("------------\n");
	ft_lstadd_front(liste, yeni);
	printf("%s\n", (*liste)->content);
	printf("%s\n", (*liste)->next->content);
	printf("%s\n", (*liste)->next->next->content);
	printf("------------\n");
	ft_lstadd_front(liste, yapistir);
	printf("%s\n", (*liste)->content);
	printf("%s\n", (*liste)->next->content);
	printf("%s\n", (*liste)->next->next->content);
	printf("%s\n", (*liste)->next->next->next->content);
	ft_lstadd_back(liste, back);
	printf("------------\n");
	printf("%s\n", (*liste)->content);
	printf("%s\n", (*liste)->next->content);
	printf("%s\n", (*liste)->next->next->content);
	printf("%s\n", (*liste)->next->next->next->content);
	printf("%s\n", (*liste)->next->next->next->next->content);
}
*/
