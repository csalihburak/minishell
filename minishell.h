/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:41:06 by agunes            #+#    #+#             */
/*   Updated: 2022/08/16 18:09:43 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "builtin/builtin.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <signal.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>

typedef struct s_token
{
	char	**path;
	char	**arglist;
	char	**command;
	int		*fd;
	int		*fd1;
	int		pr_lstfreeflag;
}		t_token;

typedef struct s_shell
{
	char		**commandlist;
	char		**env;
	char		**export;
	char		**path;
	char		*lastexe;
	char		*command;
	char		*prompt;
	int			**pipes;
	int			*pids;
	int			exeflag;
	int			echoflag;
	int			pipe_flag;
	int			envflag;
	int			builtflag;
	int			unsetflag;
	int			exportflag;
	int			freeflag;
	int			op_flag;
	t_token		*program;
}		t_shell;

t_shell	*g_shell;

t_token	*create_tokens(char *commandlist);
char	**spltnorm(char *command, int i, int k, int j);
char	**splt2norm(char *command, int i, int k, int j);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_prompt(void);
char	*merge(char **command, int status);
void	ft_parser(void);
void	runcommand(char *arr);
char	**path(char **path, char *command);
void	ft_free(void);
void	create_pipes(t_token *program);
int		exec(char **commandlist, char *path);
void	run_pipes(void);
void	ft_signal(void);
void	searchfor(char **path, char **commandlist, char *command);
void	dbfree(char **arr);
int		ft_strcmp(char *arr, char *arr1);
int		ft_builtinsearch_pipe(char *arr);
int		dblen(char **array);
int		dolar(void);
void	checkerror(char *command);
void	op_handle(char *command);
char	*deletechar(char *array, char c);
char	**exportedit(char **export);
void	exportenvcpy(char **env);
char    **ft_implt_split(char *s, char c);

#endif
