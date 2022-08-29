/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 12:43:23 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/29 10:03:50 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_close(int *arr)
{
	close(arr[0]);
	close(arr[1]);
}

void	ft_dup(int i)
{
	dup2(g_shell->pipes[i][0], 0);
	if (i + 1 != g_shell->pipe_flag)
		dup2(g_shell->pipes[i + 1][1], 1);
	ft_close(g_shell->pipes[i]);
}

void	run_with_forks(int i)
{
	while (++i < g_shell->pipe_flag)
	{
		g_shell->pids[i] = fork();
		if (g_shell->pids[i] == 0)
		{
			if (i == 0)
			{
				dup2(g_shell->pipes[i + 1][1], 1);
				ft_close(g_shell->pipes[i]);
			}
			else if (i + 1 == g_shell->pipe_flag)
			{
				dup2(g_shell->pipes[i][0], 0);
				close(g_shell->pipes[i][1]);
			}
			else
				ft_dup(i);
			create_tokens(g_shell->commandlist[i]);
			exit(0);
			return ;
		}
		ft_close(g_shell->pipes[i]);
	}
}

void	run_pipes(void)
{
	int	j;

	j = 0;
	g_shell->pids = ft_calloc(sizeof(int), g_shell->pipe_flag);
	g_shell->pipes = ft_calloc(sizeof(int *), (g_shell->pipe_flag + 1));
	while (j < (g_shell->pipe_flag))
	{
		g_shell->pipes[j] = ft_calloc(sizeof(int), 2);
		pipe(g_shell->pipes[j++]);
	}
	j = -1;
	run_with_forks(j);
	j = 0;
	while (j++ < g_shell->pipe_flag)
		wait(NULL);
	j = 0;
	while (g_shell->commandlist[j])
		free(g_shell->commandlist[j++]);
	free(g_shell->commandlist);
	j = 0;
	while (j < g_shell->pipe_flag)
		free(g_shell->pipes[j++]);
	free(g_shell->pipes);
	free(g_shell->pids);
}
