/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:54:53 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/12 18:20:29 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_op.h"

int	op_check(t_op *file)
{
	int	i;

	i = 0;
	while (file->cmd_list[i])
	{
		if (ft_strchr(file->cmd_list[i], '|'))
		{
			file->pipe_flag = 1;
			file->pipe_list = ft_split(file->cmd_list[i], '|');
			while (file->pipe_list[i++])
				file->pipe_flag++;
			file->pipe_flag -= 1;
			return (1);
		}
		else
			file->pipe_flag = 0;
		i++;
	}
	return (0);
}