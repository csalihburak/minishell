/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:00:37 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/26 13:30:45 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nod;

	nod = (t_list *)ft_calloc(sizeof(t_list), 1);
	if (!nod)
		return (0);
	nod->content = content;
	nod->next = 0;
	return (nod);
}
