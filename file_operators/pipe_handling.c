/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:49:03 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/29 10:03:48 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_op.h"

char	*pipe_handling(t_op *file, char *command)
{
	char	**temp;

	temp = ft_split(command, '|');
	file->fd_rd = -1;
	free(g_shell->command);
	g_shell->command = ft_strdup((ft_strchr(command, '|') + 1));
	free(command);
	command = ft_strdup(temp[0]);
	dbfree(g_shell->commandlist);
	parser();
	runcommand(g_shell->commandlist[0]);
	dbfree(g_shell->commandlist);
	dbfree(temp);
	g_shell->op_flag = 1;
	return (command);
}

void	less_op_norm(t_op *file)
{
	char	**temp;

	temp = ft_split_quote(file->command, ' ');
	file->pid = fork();
	if (file->pid == 0)
	{
		file->fd = open(temp[dblen2(temp) - 1], O_RDONLY);
		if (file->fd == -1)
		{
			write(2, "minishell: ", 11);
			write(2, temp[dblen2(temp) - 1], ft_strlen(temp[dblen2(temp) - 1]));
			write(2, ": No such file or directory\n", 28);
		}
		else
		{
			dup2(file->fd, 0);
			close(file->fd);
			create_ops(file, file->cmd_list[0]);
		}
		exit(0);
	}
	else
		wait(NULL);
	dbfree(temp);
}

void	less_op_handling(t_op *file)
{
	int		i;

	i = -1;
	while (file->ops[++i])
	{
		if (!ft_strcmp(file->ops[i], "<"))
			less_op_norm(file);
		else if (!ft_strcmp(file->ops[i], "<<"))
			dbl_less(file);
	}
}

void	less_norm(t_op *file)
{
	char	*temp;
	char	*dlmtr;

	dlmtr = ft_strdup(file->cmd_list[dblen2(file->cmd_list) - 1]);
	dlmtr = ft_strtrim(dlmtr, " ");
	pipe(file->fds);
	temp = ft_strdup("dlmtr");
	while (ft_strcmp(temp, dlmtr) != 0)
	{
		temp = readline("> ");
		if (temp != NULL && ft_strcmp(temp, dlmtr) != 0)
		{
			write(file->fds[1], temp, ft_strlen(temp));
			write(file->fds[1], "\n", 1);
		}
		else if (temp != NULL)
			free(temp);
	}
	close(file->fds[1]);
	dup2(file->fds[0], 0);
	close(file->fds[0]);
	create_ops(file, file->cmd_list[0]);
	exit(0);
}

void	dbl_less(t_op *file)
{
	int		pid;

	file->fds = ft_calloc(sizeof(int), 2);
	pipe(file->fds);
	pid = fork();
	if (pid == 0)
		less_norm(file);
	else
	{
		close(file->fds[0]);
		close(file->fds[1]);
		wait(NULL);
	}
	free(file->fds);
}
