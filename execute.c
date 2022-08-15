/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:08:36 by agunes            #+#    #+#             */
/*   Updated: 2022/08/15 03:05:05 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	path(char *command)
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
		command);
	}
}

int	exec(char *path)
{
	int			pid;

	pid = 0;
	pid = fork();
	if (pid == 0)
	{
		execve(path, g_shell->commandlist, g_shell->env);
		kill(getpid(), SIGTERM);
	}
	else
	{
		wait(NULL);
	}
	return (0);
}

void	searchfor(char *command)
{
	int	i;

	i = -1;
	g_shell->exeflag = 0;
	while (g_shell->path[++i])
	{
		if (access(g_shell->path[i], F_OK) == 0)
		{
			exec(g_shell->path[i]);
			g_shell->exeflag = 1;
		}
		else if (ft_strchr(command, '/'))
		{
			if (access(command, X_OK) == 0)
				exec(command);
			else
				g_shell->exeflag = -1;
		}
	}
}

void	checkerror(char *command)
{
	if (g_shell->exeflag == 0)
	{
		printf("minishell: command not found: %s\n", \
		(ft_strrchr(g_shell->path[0], '/') + 1));
	}
	if (g_shell->exeflag == -1)
		printf("minishell: %s: %s\n", command, strerror(errno));
}

void	runcommand(char *command)
{
	if (g_shell->op_flag == 1)
		op_handle(g_shell->command);
	else if (g_shell->pipe_flag > 0)
		run_pipes();
	else
	{
		path(command);
		if (ft_builtinsearch(command) == 0)
		{
			searchfor(command);
			checkerror(command);
		}
	}
}
