/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:46:27 by elima-me          #+#    #+#             */
/*   Updated: 2022/04/12 17:00:54 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	load_imgs(t_data *data)
{
	data->textures.no.img = mlx_xpm_file_to_image(data->mlx,
			data->map.no, &data->textures.no.x, &data->textures.no.y);
	data->textures.so.img = mlx_xpm_file_to_image(data->mlx,
			data->map.so, &data->textures.so.x, &data->textures.so.y);
	data->textures.we.img = mlx_xpm_file_to_image(data->mlx,
			data->map.we, &data->textures.we.x, &data->textures.we.y);
	data->textures.ea.img = mlx_xpm_file_to_image(data->mlx,
			data->map.ea, &data->textures.ea.x, &data->textures.ea.y);
	if (!data->textures.no.img || !data->textures.so.img
		|| !data->textures.we.img || !data->textures.ea.img)
		return (1);
	return (0);
}

static void	load_img_add(t_img *imgs)
{
	imgs->no.addr = mlx_get_data_addr(imgs->no.img, &imgs->no.bits_per_pixel,
			&imgs->no.line_length, &imgs->no.endian);
	imgs->so.addr = mlx_get_data_addr(imgs->so.img, &imgs->so.bits_per_pixel,
			&imgs->so.line_length, &imgs->so.endian);
	imgs->we.addr = mlx_get_data_addr(imgs->we.img, &imgs->we.bits_per_pixel,
			&imgs->we.line_length, &imgs->we.endian);
	imgs->ea.addr = mlx_get_data_addr(imgs->ea.img, &imgs->ea.bits_per_pixel,
			&imgs->ea.line_length, &imgs->ea.endian);
}

static void	load_buffer(t_img_addr *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	img->buffer = ft_calloc((TILE_SIZE * TILE_SIZE), sizeof(__uint32_t *));
	while (x < TILE_SIZE)
	{
		while (y < TILE_SIZE)
		{
			img->buffer[(TILE_SIZE * y) + x] = (__uint32_t)get_color_pxl(img, x, y);
			y++;
		}
		y = 0;
		x++;
	}
}

int	create_images(t_data *data)
{
	if (load_imgs(data))
		return (1); //ERRO DE IMAGEM INVALIDA
	load_img_add(&data->textures);
	load_buffer(&data->textures.no);
	load_buffer(&data->textures.so);
	load_buffer(&data->textures.ea);
	load_buffer(&data->textures.we);
	return (0);
}
