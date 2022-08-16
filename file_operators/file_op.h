/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_op.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:39:25 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/16 18:17:34 by scoskun          ###   ########.fr       */
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
	char	*command;
	int		pid;
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
int		dblen2(char **arr);
int		file_run(t_op *file, char **cmd_list, char *command);
int		create_file(char *arr, char *op);
void	check_and_create(t_op *file, int flag);
void	ft_path2(t_op *file, char *arr);
void	run_ops(t_op *file, int i);
void	create_ops(t_op *file, char *arr);
void	op_setup(t_op *file);
void	op_list(t_op *file);
void	check_exec(t_op *file);

#endif