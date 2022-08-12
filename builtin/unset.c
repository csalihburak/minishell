/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:56:28 by agunes            #+#    #+#             */
/*   Updated: 2022/08/12 13:02:07 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	unset(void)
{
	int	i;

	i = 1;
	g_shell->unsetflag = 1;
	while (g_shell->export[i])
	{	
		if (!exportsearch(g_shell->export[i]))
			printf("test\n");
		i++;
	}
	return (1);
}
