/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:14:13 by agunes            #+#    #+#             */
/*   Updated: 2022/08/10 10:35:10 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../minishell.h"
# include "unistd.h"

void	ft_exit(void);
void	envupdate(char *old, char *new);
char	*ft_getenv(char *arr);
int		ft_cd(char *command);
int		ft_env(void);
int		ft_builtinsearch(char *arr);
int		ft_echo(char **command);
int		ft_pwd(void);
int		ft_export(void);
int		ft_unset(void);
int		equal(void);
int		ft_envexe(void);
int		envexecupdate(char *arr);
int		runlastexec(void);
void	ft_builtfree(void);
int		eqcheck(void);
char	**exportedit(void);

#endif
