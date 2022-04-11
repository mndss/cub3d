/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:39:31 by elima-me          #+#    #+#             */
/*   Updated: 2022/04/11 15:51:55 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void    my_mlx_pixel_put(t_img_addr *img_addr, int x, int y, int color)
{
    char    *dst;

    dst = img_addr->addr + (y * img_addr->line_length + x * (img_addr->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int    draw_line(t_data *data, int ray_num)
{
    float    begin_x;
    float    end_x;

    begin_x = (WIN_HEIGHT / 2) - (data->rays[ray_num].wall_height / 2);
    end_x = (WIN_HEIGHT / 2) + (data->rays[ray_num].wall_height / 2);
    while (begin_x <= end_x)
    {
        my_mlx_pixel_put(&data->img_addr, ray_num, begin_x, 0xFFFFFF);
        begin_x++;
    }
    return (0);    
}

int    render_walls(t_data *data)
{
    int    i;

    i = 0;
	
    data->img_addr.img = mlx_new_image(data->mlx, WIN_WIDHT, WIN_HEIGHT);
    data->img_addr.addr = mlx_get_data_addr(data->img_addr.img,
        &data->img_addr.bits_per_pixel, &data->img_addr.line_length,
            &data->img_addr.endian);
    while (i < WIN_WIDHT)
    {
        draw_line(data, i);
        i++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img_addr.img, 0, 0);
	mlx_destroy_image(data->mlx, data->img_addr.img);
    return (0);
}