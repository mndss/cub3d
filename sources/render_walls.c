/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:39:31 by elima-me          #+#    #+#             */
/*   Updated: 2022/04/07 15:11:30 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	draw_line(t_data *data, int ray_num)
{
	int	begin_x;
	int	end_x;

	begin_x = (WIN_HEIGHT / 2) - (data->rays[ray_num].wall_height / 2);
	end_x = (WIN_HEIGHT / 2) + (data->rays[ray_num].wall_height / 2);
	while (begin_x <= end_x)
	{
		mlx_pixel_put(data->mlx, data->win, ray_num, begin_x, 0xFFFFFF);
		begin_x++;
	}
	return (0);	
}

int	render_walls(t_data *data)
{
	int	i;

	i = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDHT, WIN_HEIGHT, "CUB3D");
	while (i < WIN_WIDHT)
	{
		draw_line(data, i);
		i++;
	}
	mlx_loop(data->mlx);
	return (0);
}