/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_op.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:39:25 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/15 02:11:30 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_OP_H
# define FILE_OP_H

# include "../minishell.h"

typedef struct s_op
{
	char	**path;
	char	**cmd_list;
	char	**ops; // free
	char	**pipe_list;
	char	**pipe_command;
	char	*command;
	int		pipe_flag;
	int		fd_rd;
	int		**pipes;
	int		*pids;
	int		fd;
	int		*fds;
	int		fdlen;
}	t_op;

int		operator_check(char *arr);
int		op_check(t_op *file);
void	ft_path2(t_op *file, char *arr);
void	run_ops(t_op *file, int i);
void	create_ops(t_op *file, char *arr);
void	op_setup(t_op *file);
void	op_list(t_op *file);

#endif