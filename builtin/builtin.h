/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:14:13 by agunes            #+#    #+#             */
/*   Updated: 2022/08/15 04:46:04 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../minishell.h"
# include "unistd.h"

int		cd(char *command);
int		env(void);
int		builtinsearch(char *command);
int		echo(char **command);
int		pwd(void);
int		export(void);
int		equalcheck(char *commandlist);
char	*ft_getenv(char *arr);
int		exportsearch(char *arr);
int		envsearch(char *arr);
int		equalcheck(char *commandlist);
char	*addquote(char *commandlist, int status);
void	envupdate(char *commandlist);
void	addenv(char *commandlist);
void	addexport(char *commandlist);
char	**sortexport(void);
int		exportupdate(char *commandlist);
int		findfirstindex(char *arr, char c);
int		unset(void);
void	pwdupdate(char *new, char *old);
void	notset(int status);
void	envpwdupdate(char *new, char *old);
void	exportpwdupdate(char *new, char *old);
int		cdcheck(char *command);
#endif
