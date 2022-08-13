/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_op.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:39:25 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/12 16:37:12 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_OP_H
# define FILE_OP_H

# include "../minishell.h"

typedef struct s_op
{
	char	**path;
	char	**cmd_list;
	char	**ops;
	char	**pipe_list;
	char	**pipe_command;
	int		pipe_flag;
	int		fd_rd;
	int		**pipes;
	int		*pids;
}	t_op;

int		op_check(t_op *file);
void	run_ops(t_op *file, int i);
void	create_ops(t_op *file, char *arr);
void	op_setup(t_op *file);
#endif