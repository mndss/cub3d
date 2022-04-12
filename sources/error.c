/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:36:40 by guferrei          #+#    #+#             */
/*   Updated: 2022/04/12 19:59:04 by elima-me         ###   ########.fr       */
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
	err[ERR_INVALID_COLOR] = "Error\nInvalid color\n";
	err[ERR_INVALID_TEXTURE] = "Error\nInvalid texture\n";
	ft_putstr_fd(err[msg], 2);
	return (msg + 1);
}
