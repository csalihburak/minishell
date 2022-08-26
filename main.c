/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:33:50 by agunes            #+#    #+#             */
/*   Updated: 2022/08/26 13:28:48 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(void)
{
	g_shell->prompt = ft_prompt();
	g_shell->command = readline(g_shell->prompt);
	free(g_shell->prompt);
}

int	is_valid(char *arr)
{
	int	i;

	i = -1;
	while (arr[++i])
	{
		if (ft_isprint(arr[i]))
			return (1);
	}
	return (0);
}

void	start(void)
{
	ft_signal();
	prompt();
	if (g_shell->command != NULL)
	{
		if (is_valid(g_shell->command))
		{
			add_history(g_shell->command);
			ft_free();
			parser();
			dolar();
			if (g_shell->commandlist[0])
				runcommand(g_shell->commandlist[0]);
			free(g_shell->command);
		}
		else
			free(g_shell->command);
	}
	if (g_shell->command == NULL)
	{
		printf("exit\n");
		exit(0);
	}
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	g_shell = ft_calloc(sizeof(t_shell), 1);
	exportenvcpy(env);
	while (1)
		start();
	return (0);
}
