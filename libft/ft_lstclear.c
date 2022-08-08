/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:45:58 by agunes            #+#    #+#             */
/*   Updated: 2022/01/22 14:20:26 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	del(void *b)
{
	if (ft_strncmp((char*)b, "ahmet", ft_strlen((char *)b)) == 0)
	{
		printf("SİLME İŞLEMİ BAŞARILI\n");
		ft_bzero((char *)b, ft_strlen((char *)b));
		free(b);
	}
	printf("İçeriğiniz farklı olduğu için silme işlemi yapılamadı.");
}
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*a;

	a = *lst;
	if (a == NULL || lst == NULL || del == NULL)
	{
		return ;
	}
	while (*lst != NULL)
	{
		a = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = a;
	}
	*lst = NULL;
}
/*
int	main(void)
{
	t_list	**liste;
	t_list	*a;

	liste = (t_list **)malloc(sizeof(t_list) * 2);
	a = (t_list *)malloc(sizeof(t_list));
	liste = &a;
	a->content = "ahmet";
	ft_lstclear(liste, del);
}
*/
