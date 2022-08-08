/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 12:43:23 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/08 17:32:56 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	run_pipes(void)
{
	int	i;
	int	j;
	int	*pids;
	int	len;

	i = 0;
	j = 0;
	len = g_shell->pipe_flag;
	pids = malloc(sizeof(int) * len);
	g_shell->pipes = malloc(sizeof(int *) * (len + 1));
	while (i < (len))
	{
		g_shell->pipes[i] = malloc(sizeof(int) * 2);
		pipe(g_shell->pipes[i]);
		i++;
	}
	i = 0;
	while (i < len)
	{
		pids[i] = fork();
		if (pids[i] == 0)
		{
			if (i  == 0)
			{
				dup2(g_shell->pipes[i + 1][1], 1);
				close(g_shell->pipes[i][1]);
				close(g_shell->pipes[i][0]);
			}
			else if (i + 1 == len)
			{
				dup2(g_shell->pipes[i][0], 0);
				close(g_shell->pipes[i][1]);
			}
			else
			{
				dup2(g_shell->pipes[i][0], 0);
				if (i + 1 != len)
					dup2(g_shell->pipes[i + 1][1], 1);
				close(g_shell->pipes[i][1]);
				close(g_shell->pipes[i][0]);
			}
			create_tokens(g_shell->commandlist[i]);
			kill(getpid(), SIGTERM);
			return ;
		}
		close(g_shell->pipes[i][1]);
		close(g_shell->pipes[i][0]);
		i++;
	}
	j = 0;
	while (j++ < len)
		wait(NULL);
	j = 0;
	while (g_shell->commandlist[j])
		free(g_shell->commandlist[j++]);
	free(g_shell->commandlist);
	j = 0;
	while (j < len)
		free(g_shell->pipes[j++]);
	free(g_shell->pipes);
	free(pids);
}