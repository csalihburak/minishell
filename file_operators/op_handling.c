/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:27:38 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/15 21:25:30 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_op.h"

int	dblen2(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	create_file(char *arr, char *op)
{
	int	fd;

	fd = -1;
	if (!ft_strcmp(op, ">"))
		fd = open(arr, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	else if (!ft_strcmp(op, ">>"))
		fd = open(arr, O_APPEND | O_RDWR, 0777);
	return (fd);
}

void	check_and_create(t_op *file)
{
	char	**temp;
	char	**buff;
	char	*path;
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	while (file->cmd_list[++i])
	{
		temp = ft_split(file->cmd_list[i], ' ');
		ft_path2(file, temp[0]);
		j = -1;
		while (file->path[++j])
		{
			if (!access(file->path[j], X_OK))
			{
				buff = ft_split(file->cmd_list[i], ' ');
				path = ft_strdup(file->path[j]);
				break ;
			}
		}
		if (j == dblen2(file->path))
			file->fds[k++] = create_file(temp[0], file->ops[i - 1]);
		dbfree(temp);
		dbfree(file->path);
	}
	file->fdlen = k;
	int	pid = fork();
	if (pid == 0)
	{
		dup2(file->fds[k - 1], 1);
		close(file->fds[k - 1]);
		execve(path, buff, g_shell->env);
	}
	else
		wait(NULL);
	close(file->fds[k - 1]);
	i = 0;
	while (i < k)
		close(file->fds[i++]);
}

void	op_handle(char *command)
{
	t_op	*file;
	int		i;

	i = 0;
	file = malloc(sizeof(t_op));
	command = merge(g_shell->commandlist, 1);
	file->command = command;
	file->cmd_list = ft_split(command, ' ');
	op_list(file);
	dbfree(file->cmd_list);
	file->cmd_list = ft_split(command, '>');
	file->fds = malloc(sizeof(int) * dblen2(file->ops));
	if (op_check(file))
	{
		op_setup(file);
		dbfree(file->pipe_list);
	}
	else
		check_and_create(file);
	dbfree(g_shell->commandlist);
	dbfree(file->cmd_list);
	dbfree(file->ops);
	free(file);
}

/* 	for(int i = 0; file->cmd_list[i]; i++)
		printf("[%d] %s\n",i, file->cmd_list[i]);
	for(int i = 0; file->ops[i]; i++)
		printf("[%d] %s\n", i, file->ops[i]); */