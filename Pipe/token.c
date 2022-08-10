/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:49:29 by agunes            #+#    #+#             */
/*   Updated: 2022/08/10 15:54:34 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_path1(t_token *program)
{
	int		i;

	i = -1;
	while (g_shell->env[++i])
	{
		if (ft_strncmp(g_shell->env[i], "PATH", 4) == 0)
			break ;
	}
	program->path = ft_split(g_shell->env[i], ':');
	free(program->path[0]);
	program->path[0] = ft_strdup((ft_strchr(program->path[0], '=') + 1));
	i = -1;
	while (program->path[++i])
	{
		program->path[i] = ft_strjoin(program->path[i], "/");
		program->path[i] = ft_strjoin(program->path[i], \
		program->command[0]);
	}
	i = -1;
}

int	ft_execve2(char *arr, char **lst, char **env)
{
	int	i;

	i = 0;
	execve(arr, lst, env);
	while (lst[i])
		free(lst[i++]);
	free(lst);
	kill(getpid(), SIGTERM);
	return (0);
}

int	ft_searchfor3(t_token *program, int flag, int i)
{
	while (program->path[++i])
	{
		if (access(program->path[i], F_OK) == 0)
			ft_execve2(program->path[i], program->command, \
			g_shell->env);
		if (ft_strchr(program->command[0], '/'))
		{
			if (access(program->command[0], X_OK) == 0)
				ft_execve2(program->command[0], program->command, \
				g_shell->env);
			else if (access(program->command[0], X_OK) == -1)
				flag = 1;
		}
	}
	if (flag == 0)
	{
		printf("minishell: command not found: %s\n", \
		(ft_strrchr(program->path[0], '/') + 1));
	}
	return (flag);
}

t_token	*create_tokens(char *commandlist)
{
	t_token	*program;
	int		flag;
	int		i;

	i = 0;
	flag = 2;
	program = malloc(sizeof(t_token));
	g_shell->program = program;
	program->command = ft_split(commandlist, ' ');
	ft_path1(program);
	if (ft_builtinsearch_pipe(program->command[0]) == 0)
	{
		flag = ft_searchfor3(program, flag, -1);
		if (flag == 1)
			printf("minishell: %s: %s\n", strerror(errno), \
			g_shell->commandlist[0]);
	}
	return (program);
}
