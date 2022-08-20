/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_op_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:35:33 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/20 17:21:24 by scoskun          ###   ########.fr       */
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

void	op_list(t_op *file)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	file->ops = malloc(sizeof(char *) * 100);
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

void	op_setup(t_op *file)
{
	int	i;

	i = -1;
	file->pids = malloc(sizeof(int) * file->pipe_flag);
	file->pipes = malloc(sizeof(int *) * (file->pipe_flag));
	while (++i < (file->pipe_flag))
	{
		file->pipes[i] = malloc(sizeof(int) * 2);
		pipe(file->pipes[i]);
	}
	run_ops(file, -1);
	i = 0;
	while (i++ < file->pipe_flag)
		wait(NULL);
	i = -1;
	free(file->pids);
	i = 0;
	while (i < file->pipe_flag)
		free(file->pipes[i++]);
	free(file->pipes);
}
