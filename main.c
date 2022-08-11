/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:33:50 by agunes            #+#    #+#             */
/*   Updated: 2022/08/11 11:54:29 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	envcpy(char **env)
{
	char	*buff;

	buff = merge(env);
	g_shell->env = ft_split(buff, ' ');
	g_shell->export = ft_split(buff, ' ');
	free(buff);
}

void	prompt(void)
{
	g_shell->prompt = ft_prompt();
	g_shell->command = readline(g_shell->prompt);
	free(g_shell->prompt);
}

void	start(void)
{
	ft_signal();
	prompt();
	if (g_shell->command != NULL)
	{
		if (g_shell->command[0] > 0)
		{
			ft_free();
			ft_parser();
			if (g_shell->commandlist[0])
				runcommand(g_shell->commandlist[0]);
			else if (g_shell->command[0] == '|')
				printf("minishell: parse error near `%s'\n", g_shell->command);
			add_history(g_shell->command);
			free(g_shell->command);
		}
		else
			free(g_shell->command);
	}
	if (g_shell->command == NULL)
		exit(0);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	g_shell = malloc(sizeof(t_shell));
	envcpy(env);
	while (1)
		start();
	return (0);
}
