/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:39:31 by elima-me          #+#    #+#             */
/*   Updated: 2022/04/12 19:34:52 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	my_pixel_put(t_img_addr *img_addr, int x, int y, int color)
{
	char	*dst;

	dst = img_addr->addr + (y * img_addr->line_length \
			+ x * (img_addr->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	render_walls(t_data *data)
{
	int	i;

	i = 0;
	data->main_img.img = mlx_new_image(data->mlx, WIN_WIDHT, WIN_HEIGHT);
	data->main_img.addr = mlx_get_data_addr(data->main_img.img,
			&data->main_img.bits_per_pixel, &data->main_img.line_length,
			&data->main_img.endian);
	render_textures(data);
	mlx_put_image_to_window(data->mlx, data->win, data->main_img.img, 0, 0);
	mlx_destroy_image(data->mlx, data->main_img.img);
	return (0);
}
