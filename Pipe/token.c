/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:49:29 by agunes            #+#    #+#             */
/*   Updated: 2022/08/26 13:33:17 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*create_tokens(char *commandlist)
{
	t_token	*program;

	program = ft_calloc(sizeof(t_token), 1);
	g_shell->program = program;
	program->command = ft_split_quote(commandlist, ' ');
	program->path = path(program->path, program->command[0]);
	g_shell->builtflag = 1;
	if (builtinsearch(program->command[0]) == 0)
	{
		searchfor(program->path, program->command, program->command[0]);
		checkerror(program->command[0]);
	}
	return (program);
}
