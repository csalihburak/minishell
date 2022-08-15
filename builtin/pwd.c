/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:31:24 by agunes            #+#    #+#             */
/*   Updated: 2022/08/15 04:45:49 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	pwd(void)
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
	write(1, buff, ft_strlen(buff));
	write(1, "\n", 1);
	free(buff);
	return (1);
}
