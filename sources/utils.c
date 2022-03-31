/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:36:40 by guferrei          #+#    #+#             */
/*   Updated: 2022/03/31 16:01:55 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	print_err(int msg)
{
	char	*err[ERROR_SIZE];

	err[ERR_ARGS] = "Error\nInvalid numbers of arguments\n";
	err[ERR_INVALID_EXT] = "Error\nInvalid extension from map\n";
	err[ERR_NOT_FOUND] = "Error\nFile not found\n";
	err[ERR_DOUBLE_PLAYER] = "Error\nMap have two or more players\n";
	err[ERR_NO_PLAYER] = "Error\nMap don't have player\n";
	err[ERR_INVALID_MAP] = "Error\nInvalid map\n";
	ft_putstr_fd(err[msg], 2);
	return (msg + 1);
}

void	free_matrix(char **ptr)
{
	int	count;

	count = 0;
	while (ptr[count])
	{
		free(ptr[count]);
		count++;
	}
	free(ptr);
}
