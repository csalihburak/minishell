/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:26:27 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/06 11:13:48 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	create_pipes(t_token *program)
{
	int	i;
	int	**fd;

	i = 0;
	fd = malloc(sizeof(int *) * (g_shell->pipe_flag + 1));
	while (i < g_shell->pipe_flag + 1)
	{
		fd[i] = malloc(sizeof(int) * 2);
		pipe(fd[i]);
		program[i].fd = fd[i];
		program[i].fd1 = fd[(i + 1) % g_shell->pipe_flag];
		i++;
	}
}