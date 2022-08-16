/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:54:53 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/16 16:23:59 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_op.h"

int	file_run(t_op *file, char **cmd_list)
{
	int	i;

	i = -1;
	while (file->path[++i])
	{
		if (!access(file->path[i], X_OK))
		{
			dup2(file->fd, 1);
			exec(cmd_list, file->path[i]);
			close(file->fd);
		}
	}
	return (1);
}

void	check_exec(t_op *file)
{
	int		i;
	int		k;
	int		fd;

	i = 1;
	k = 0;
	while (file->cmd_list[i + 1])
	{
		fd = create_file(file->cmd_list[i], file->ops[i - 1]);
		printf("%d\n", fd);
		close(fd);
		i++;
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

void	op_list(t_op *file)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	file->ops = malloc(sizeof(char *) * dblen(file->cmd_list));
	while (file->command[++i])
	{
		if (file->command[i] == '>' && file->command[i + 1] != '>')
			file->ops[j++] = ft_strdup(">");
		else if (file->command[i] == '>' && file->command[i + 1] == '>')
			file->ops[j++] = ft_strdup(">>");
		else if (file->command[i] == '<' && file->command[i + 1] == '<')
			file->ops[j++] = ft_strdup("<<");
		else if (file->command[i] == '<' && file->command[i + 1] != '<')
			file->ops[j++] = ft_strdup("<");
	}
	file->ops[j] = NULL;
}

int	op_check(t_op *file)
{
	int	i;

	i = 0;
	while (file->cmd_list[i])
	{
		if (ft_strchr(file->cmd_list[i], '|'))
		{
			file->pipe_flag = 0;
			file->pipe_list = ft_split(file->cmd_list[i], '|');
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
