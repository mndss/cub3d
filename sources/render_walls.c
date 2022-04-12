/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:39:31 by elima-me          #+#    #+#             */
/*   Updated: 2022/04/11 21:14:03 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	my_mlx_pixel_put(t_img_addr *img_addr, int x, int y, int color)
{
	char	*dst;

	dst = img_addr->addr + (y * img_addr->line_length \
			+ x * (img_addr->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	render_floor_n_sky(t_data *data)
{
	int	countx;
	int	county;

	countx = 0;
	county = 0;
	while (county < WIN_WIDHT)
	{
		while (countx < WIN_HEIGHT)
		{
			if (countx < WIN_HEIGHT / 2)
				my_mlx_pixel_put(&data->img_addr, county, countx,
					data->map.color_c);
			else
				my_mlx_pixel_put(&data->img_addr, county, countx,
					data->map.color_f);
			countx++;
		}
		county++;
		countx = 0;
	}
}

int	draw_line(t_data *data, int ray_num)
{
	float	begin_x;
	float	end_x;
	int		tone;

	tone = ((255 * 4) - data->rays[ray_num].distance) / 4;
	if (tone < 0)
		tone = 0;
	if (data->rays[ray_num].wall_height > WIN_HEIGHT)
	{
		begin_x = 0;
		end_x = WIN_HEIGHT - 1;
	}
	else
	{
		begin_x = (WIN_HEIGHT / 2) - (data->rays[ray_num].wall_height / 2);
		end_x = (WIN_HEIGHT / 2) + (data->rays[ray_num].wall_height / 2);
	}
	while (begin_x <= end_x)
	{
		my_mlx_pixel_put(&data->img_addr, ray_num, begin_x,
			(tone * 65536 + tone * 256 + tone));
		begin_x++;
	}
	return (0);
}

int	render_walls(t_data *data)
{
	int	i;

	i = 0;
	data->img_addr.img = mlx_new_image(data->mlx, WIN_WIDHT, WIN_HEIGHT);
	data->img_addr.addr = mlx_get_data_addr(data->img_addr.img,
			&data->img_addr.bits_per_pixel, &data->img_addr.line_length,
			&data->img_addr.endian);
	render_floor_n_sky(data);
	while (i < WIN_WIDHT)
	{
		draw_line(data, i);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img_addr.img, 0, 0);
	mlx_destroy_image(data->mlx, data->img_addr.img);
	return (0);
}
