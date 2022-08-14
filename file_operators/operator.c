/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:50:20 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/14 02:52:50 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_op.h"

void	ft_path2(t_op *file)
{
	int		i;

	i = -1;
	while (g_shell->env[++i])
	{
		if (ft_strncmp(g_shell->env[i], "PATH", 4) == 0)
			break ;
	}
	file->path = ft_split(g_shell->env[i], ':');
	free(file->path[0]);
	file->path[0] = ft_strdup((ft_strchr(file->path[0], '=') + 1));
	i = -1;
	while (file->path[++i])
	{
		file->path[i] = ft_strjoin(file->path[i], "/");
		file->path[i] = ft_strjoin(file->path[i], \
		file->pipe_command[0]);
	}
	i = -1;
}

int	ft_execve3(char *arr, char **lst, char **env)
{
	int	i;

	i = 0;
	execve(arr, lst, env);
	kill(getpid(), SIGTERM);
	return (0);
}

int	ft_searchfor4(t_op *file, int flag, int i)
{
	while (file->path[++i])
	{
		if (access(file->path[i], F_OK) == 0)
			ft_execve3(file->path[i], file->pipe_command, \
			g_shell->env);
		if (ft_strchr(file->pipe_command[0], '/'))
		{
			if (access(file->pipe_command[0], X_OK) == 0)
				ft_execve3(file->pipe_command[0], file->pipe_command, \
				g_shell->env);
			else if (access(file->pipe_command[0], X_OK) == -1)
				flag = 1;
		}
	}
	if (flag == 0)
	{
		printf("minishell: command not found: %s\n", \
		(ft_strrchr(file->path[0], '/') + 1));
	}
	return (flag);
}

void	create_ops(t_op *file, char *command)
{
	int	flag;

	flag = 2;
	file->pipe_command = ft_split(command, ' ');
	ft_path2(file);
	flag = ft_searchfor4(file, flag, -1);
	if (flag == 1)
		printf("minishell: %s: %s\n", strerror(errno), file->pipe_command[0]);
	dbfree(file->pipe_command);
	dbfree(file->path);
}
