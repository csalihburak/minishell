/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:38:34 by scoskun           #+#    #+#             */
/*   Updated: 2022/01/10 17:38:57 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*tmp;

	while ((*lst))
	{
		tmp = (*lst)->next;
		ft_lstdelone((*lst), del);
		*lst = tmp;
	}
	*lst = NULL;
}
