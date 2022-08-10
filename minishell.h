/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:41:06 by agunes            #+#    #+#             */
/*   Updated: 2022/08/10 18:15:43 by agunes           ###   ########.fr       */
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
	char	**path; //free
	char	**arglist; //free
	char	**command;
	int		*fd;	//to_write
	int		*fd1;	//to_read
	int		pr_lstfreeflag;
}		t_token;

typedef struct s_shell
{
	char		**commandlist; //free
	char		**env;
	char		**path;		//free
	char		*command;
	char		*prompt;
	char		*envexe;
	int			echoflag;
	int			free_flag;
	int			pipe_flag;
	int			**pipes;
	int			*pids;
	int			exportflag;
	int			pathflag;
	t_token		*program;
}		t_shell;

t_shell	*g_shell;

t_token	*create_tokens(char *commandlist);
char	*ft_prompt(void);
int		ft_strcmp(char *arr, char *arr1);
char	*ft_strjoin(char *s1, char *s2);
void	ft_parser(void);
char	**spltnorm(char *command, int i, int k, int j);
char	**splt2norm(char *command, int i, int k, int j);
void	runcommand(char *arr);
int		ft_commandsearch(void);
void	ft_path(char *arr);
void	ft_free(void);
char	*merge(char **command);
int		ft_builtinsearch_pipe(char *arr);
void	create_pipes(t_token *program);
void	run_pipes(void);
int		dblen(char **array);
void	ft_signal(void);
void	ft_searchfor(char *arr);
int		dblen2(char **array);
#endif
