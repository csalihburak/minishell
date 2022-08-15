/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:31:24 by agunes            #+#    #+#             */
/*   Updated: 2022/08/15 02:33:58 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_pwd(void)
{
	int		i;
	char	*buff;

	i = 0;
	while (g_shell->env[i++])
	{
		if (!ft_strncmp(g_shell->env[i], "PWD", 3))
			break ;
	}
	buff = ft_strdup("");
	buff = ft_strjoin(buff, g_shell->env[i] + 4);
	printf("%s\n", buff);
	free(buff);
	return (1);
}
