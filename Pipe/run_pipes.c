/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 12:43:23 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/08 14:54:56 by scoskun          ###   ########.fr       */
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
	while (i < (len + 1))
	{
		g_shell->pipes[i] = malloc(sizeof(int) * 2);
		pipe(g_shell->pipes[i]);
		i++;
	}
	printf("len =) %d\n", len);
	i = 0;
	while (i < len)
	{
		printf("i = %d\n", i);
		pids[i] = fork();
		if (pids[i] == 0) //Child process
		{
			if (i % 2 == 0)
			{
				dup2(g_shell->pipes[i + 1][0], 0);
				dup2(g_shell->pipes[i + 1][1], STDOUT_FILENO);
				close(g_shell->pipes[i][1]);
				close(g_shell->pipes[i][0]);
			}
			else
			{
				dup2(g_shell->pipes[i][0], STDIN_FILENO);
				if (i + 1 != len)
					dup2(g_shell->pipes[i + 1][1], 1);
				close(g_shell->pipes[i][1]);
				close(g_shell->pipes[i][0]);
			}
			create_tokens(g_shell->commandlist[i]);
			kill(getpid(), SIGINT);
			return ;
		}
		i++;
	}
	j = 0;
	while (j < (len))
	{
		close(g_shell->pipes[j][0]);
		close(g_shell->pipes[j][1]);
		j++;
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