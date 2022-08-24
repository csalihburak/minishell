/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:49:03 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/24 14:42:07 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_op.h"

char	*pipe_handling(t_op *file, char *command)
{
	char	**temp;
	int		i;
	int		k;

	k = 0;
	i = 0;
	temp = ft_split_quote(command, '|');
	file->fd_rd = -1;
	dbfree(g_shell->commandlist);
	parser();
	runcommand(g_shell->commandlist[0]);
	return (command);
}

void	less_op_handling(t_op *file)
{
	int		i;
	char	**temp;

	i = -1;
	while (file->ops[++i])
	{
		if (!ft_strcmp(file->ops[i], "<"))
		{
			temp = ft_split_quote(file->command, ' ');
			file->pid = fork();
			if (file->pid == 0)
			{
			printf("selam\n");
				file->fd = open(temp[dblen2(temp) - 1], O_RDONLY);
				dup2(file->fd, 0);
				close(file->fd);
				create_ops(file, file->cmd_list[0]);
				kill(getpid(), SIGTERM);
			}
			else
				wait(NULL);
			dbfree(temp);
		}
		else if (!ft_strcmp(file->ops[i], "<<"))
			dbl_less(file);
	}
}

void	dbl_less(t_op *file)
{
	int		i;
	char	*temp;
	char	*dlmtr;

	i = -1;
	file->fds = malloc(sizeof(int) * 2);
	pipe(file->fds);
	dlmtr = file->cmd_list[dblen2(file->cmd_list) - 1];
	temp = ft_strdup("evet");
	while (ft_strcmp(temp,dlmtr) != 0)
	{
		temp = readline(">");
		write(file->fds[1], temp, ft_strlen(temp));
	}
	dup2(file->fds[0], 0);
	dup2(file->fd, 0);
	close(file->fd);
	create_ops(file, file->cmd_list[0]);
}
