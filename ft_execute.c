/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:08:36 by agunes            #+#    #+#             */
/*   Updated: 2022/08/14 02:28:48 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_path(char *arr)
{
	int		i;

	i = -1;
	while (g_shell->env[++i])
	{
		if (!ft_strncmp(g_shell->env[i], "PATH", 4) && \
		g_shell->env[i][4] == '=')
			break ;
	}
	g_shell->path = ft_split(g_shell->env[i], ':');
	free(g_shell->path[0]);
	g_shell->path[0] = ft_strdup((ft_strchr(g_shell->path[0], '=') + 1));
	i = -1;
	while (g_shell->path[++i])
	{
		g_shell->path[i] = ft_strjoin(g_shell->path[i], "/");
		g_shell->path[i] = ft_strjoin(g_shell->path[i], \
		arr);
	}
}

int	ft_execve(int i)
{
	int			pid;

	pid = 0;
	pid = fork();
	if (pid == 0)
	{
		execve(g_shell->path[i], g_shell->commandlist, g_shell->env);
		kill(getpid(), SIGTERM);
	}
	else
	{
		wait(NULL);
	}
	return (0);
}

void	ft_searchfor2(void)
{
	int	i;

	i = -1;
	while (g_shell->path[++i])
	{
		if (access(g_shell->path[i], F_OK) == 0)
		{
			g_shell->exeflag = 2;
			ft_execve(i);
		}
		if (ft_strchr(g_shell->commandlist[0], '/'))
		{
			if (access(g_shell->commandlist[0], X_OK) == 0)
			{
				g_shell->exeflag = 2;
				ft_execve(i);
			}
			else if (access(g_shell->commandlist[0], X_OK) == -1)
				g_shell->exeflag = 1;
		}
	}
}

void	ft_searchfor(char *arr)
{
	g_shell->exeflag = 0;
	ft_searchfor2();
	if (g_shell->exeflag == 0)
	{
		printf("minishell: command not found: %s\n", \
		(ft_strrchr(g_shell->path[0], '/') + 1));
	}
	if (g_shell->exeflag == 1)
		printf("minishell: %s: %s\n", arr, strerror(errno));
}

void	runcommand(char *arr)
{
	if (g_shell->op_flag == 1)
		op_handle(g_shell->command);
	else if (g_shell->pipe_flag > 0)
		run_pipes();
	else
	{
		ft_path(arr);
		if (ft_builtinsearch(arr) == 0)
			ft_searchfor(arr);
	}
}
