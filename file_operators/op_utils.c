/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:54:53 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/27 15:52:54 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_op.h"

void	file_fork(t_op *file, char **cmd_list, int i, int flag)
{
	if (flag == 0)
	{
		file->pid = fork();
		if (file->pid == 0)
		{
			dup2(file->fd, 1);
			close(file->fd);
			exec(cmd_list, file->path[i]);
			kill(getpid(), SIGTERM);
		}
		return ;
	}
	file->pid = fork();
	if (file->pid == 0)
	{
		dup2(file->fd, 1);
		close(file->fd);
		exec(cmd_list, file->command);
		kill(getpid(), SIGTERM);
	}
}

int	file_run(t_op *file, char **cmd_list, char *command)
{
	int	i;

	i = -1;
	file->command = command;
	while (file->path[++i])
	{
		if (!access(file->path[i], X_OK))
		{
			file_fork(file, cmd_list, i, 0);
			close(file->fd);
			wait(NULL);
		}
		else if (ft_strchr(command, '/'))
		{
			if (!access(command, X_OK))
			{
				file_fork(file, cmd_list, 0, 1);
				close(file->fd);
				wait(NULL);
				break ;
			}
		}
	}
	return (1);
}

void	check_exec(t_op *file)
{
	int		i;
	int		fd;
	char	*temp;

	i = 0;
	fd = 0;
	temp = (ft_strrchr(file->command, '>') - 1);
	while (file->cmd_list && file->cmd_list[++i])
	{
		if (quote_strchr(file->cmd_list[i], '|'))
			file->cmd_list[i] = pipe_handling(file, file->cmd_list[i]);
		fd = create_file(file->cmd_list[i], file->ops[i - 1]);
		if (!file->cmd_list[i + 1])
			file->fd = fd;
		else
			close(fd);
	}
}

int	operator_check(char *arr)
{
	if (ft_strncmp(arr, ">", 1) == 0)
		return (1);
	else if (ft_strncmp(arr, ">>", 2) == 0)
		return (1);
	else if (ft_strncmp(arr, "<", 1) == 0)
		return (1);
	else if (ft_strncmp(arr, "<<", 2) == 0)
		return (1);
	return (0);
}

int	op_check(t_op *file)
{
	int	i;

	i = 0;
	dbfree(file->cmd_list);
	file->cmd_list = ft_split_quote(file->command, '>');
	while (file->cmd_list[i])
	{
		if (quote_strchr(file->cmd_list[i], '|'))
		{
			file->pipe_flag = 0;
			file->pipe_list = ft_split_quote(file->cmd_list[i], '|');
			while (file->pipe_list[i++])
				file->pipe_flag++;
			return (1);
		}
		else
			file->pipe_flag = 0;
		i++;
	}
	return (0);
}
