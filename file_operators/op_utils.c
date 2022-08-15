/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:54:53 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/14 22:25:22 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_op.h"

int	operator_check(char *arr)
{
	if (ft_strncmp(arr, ">", 1) == 0)
		return (1);
	else if (ft_strncmp(arr, ">>", 2) == 0)
		return (1);
	else if (ft_strncmp(arr, "<", 1) == 0)
		return (1);
	else if (ft_strncmp(arr, "<<", 2) == 0)
		return (1);
	return (0);
}

void	op_list(t_op *file)
{
	int		i;
	int		j;
	char	**temp;

	i = 0;
	j = 0;
	file->ops = malloc(sizeof(char *) * dblen(file->cmd_list));
	temp = ft_split(file->command, ' ');
	while (temp[i])
	{
		if (operator_check(temp[i]))
			file->ops[j++] = ft_strdup(temp[i]);
		i++;
	}
	file->ops[j] = NULL;
	dbfree(temp);
}

int	op_check(t_op *file)
{
	int	i;

	i = 0;
	while (file->cmd_list[i])
	{
		if (ft_strchr(file->cmd_list[i], '|'))
		{
			file->pipe_flag = 0;
			file->pipe_list = ft_split(file->cmd_list[i], '|');
			while (file->pipe_list[i++])
				file->pipe_flag++;
			return (1);
		}
		else
			file->pipe_flag = 0;
		i++;
	}
	return (0);
}