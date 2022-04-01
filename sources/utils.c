/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:36:40 by guferrei          #+#    #+#             */
/*   Updated: 2022/04/01 15:47:47 by elima-me         ###   ########.fr       */
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

int	rgb_to_decimal(char **colors)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	if ((r > 255 || r < 0) || (g > 255 || g < 0) || (b > 255 || b < 0))
		return (-1);
	return (r * 65536 + g * 256 + b);
}

int	set_colors(char *str_color)
{
	char	**colors;
	int		dec_color;
	int		i;

	i = 0;
	colors = ft_split(str_color, ',');
	while (colors[i])
		i++;
	if (i != 3)
		return (-1);
	dec_color = rgb_to_decimal(colors);
	free_matrix(colors);
	return (dec_color);
}
