/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:14:13 by agunes            #+#    #+#             */
/*   Updated: 2022/08/08 14:54:17 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../minishell.h"
# include "unistd.h"

int		ft_cd(char *command);
void	envupdate(char *old, char *new);
int		ft_env(void);
int		ft_builtinsearch(char *arr);
int		ft_echo(char **command);
int		ft_pwd(void);
void	ft_exit(void);
int		ft_export(void);
int		ft_unset(void);
int		equal(void);
int		ft_envexe(void);

#endif
