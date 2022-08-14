/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:33:50 by agunes            #+#    #+#             */
/*   Updated: 2022/08/14 19:18:36 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*exportedit(char *export)
{
	char	*temp;

	temp = NULL;
	if (!ft_strncmp(export, "OLDPWD=", 7))
	{
		free(export);
		export = ft_strdup("OLDPWD");
		return (export);
	}
	else
	{
		if (equalcheck(export))
		{
			temp = export;
			export = addquote(export);
			free(temp);
			return (export);
		}
	}
	return (export);
}

void	exportenvcpy(char **env)
{
	int		i;
	char	*buff;

	i = -1;
	buff = merge(env);
	g_shell->env = ft_split(buff, ' ');
	g_shell->export = ft_split(buff, ' ');
	while (g_shell->export[++i])
		g_shell->export[i] = exportedit(g_shell->export[i]);
	free(g_shell->export[i - 1]);
	g_shell->export[i - 1] = NULL;
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
			dolar();
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
	exportenvcpy(env);
	while (1)
		start();
	return (0);
}
