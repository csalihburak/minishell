/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:54:02 by agunes            #+#    #+#             */
/*   Updated: 2022/01/21 17:25:29 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*root;

	root = (t_list *)malloc(sizeof(t_list));
	if (root == NULL)
		return (NULL);
	root->content = content;
	root->next = NULL;
	return (root);
}
/*
int	main(void)
{
	t_list	*node;

	node = ft_lstnew("ahmet");
	printf("%s", node->content);
}
*/