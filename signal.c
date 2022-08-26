/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 10:36:18 by agunes            #+#    #+#             */
/*   Updated: 2022/08/26 12:08:11 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

void	ft_sig(int signo)
{
	if (signo == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		if (g_shell->pipe_flag == 0)
			rl_redisplay();
	}
	else if (signo == SIGQUIT)
	{
		return;
	}
}

void	ft_signal(void)
{
	signal(SIGINT, ft_sig);
	signal(SIGQUIT, ft_sig);
}
