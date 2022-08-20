/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:00:37 by scoskun           #+#    #+#             */
/*   Updated: 2022/01/10 15:07:40 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nod;

	nod = (t_list *)malloc(sizeof(t_list));
	if (!nod)
		return (0);
	nod->content = content;
	nod->next = 0;
	return (nod);
}
