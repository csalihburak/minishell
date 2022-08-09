/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:14:13 by agunes            #+#    #+#             */
/*   Updated: 2022/08/09 12:24:29 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../minishell.h"
# include "unistd.h"

void	ft_exit(void);
void	envupdate(char *old, char *new);
char	*ft_getenv(void);
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

#endif
