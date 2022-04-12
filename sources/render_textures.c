/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:50:58 by guferrei          #+#    #+#             */
/*   Updated: 2022/04/12 16:45:03 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	get_proj_info(t_proj *proj, t_data *data, int x)
{
	proj->dist_persp = data->rays[x].distance *
		cos(data->rays[x].ray_angle - data->player.direction);
	proj->wall_height_proj = (TILE_SIZE / proj->dist_persp) *
		((WIN_WIDHT / 2) / tan(data->fov_angle / 2));
	proj->wall_strip_height = (int)proj->wall_height_proj;
	proj->wall_top_pxl = (WIN_HEIGHT / 2) - (proj->wall_strip_height / 2);
	if (proj->wall_top_pxl < 0)
		proj->wall_top_pxl = 0;
	if (proj->wall_top_pxl > WIN_HEIGHT)
		proj->wall_top_pxl = WIN_HEIGHT;
	proj->wall_bot_pxl = (WIN_HEIGHT / 2) + (proj->wall_strip_height / 2);
	if (proj->wall_bot_pxl < 0)
		proj->wall_bot_pxl = 0;
	if (proj->wall_bot_pxl > WIN_HEIGHT)
		proj->wall_bot_pxl = WIN_HEIGHT;
}

void	drawn_ceiling(t_img_addr *main_img, t_map_info *map, t_proj *proj, int x)
{
	int	y;

	y = 0;
	while (y < proj->wall_top_pxl)
	{
		my_pixel_put(main_img, x, y, map->color_c);
		y++;
	}
}

void	drawn_floor(t_img_addr *main_img, t_map_info *map, t_proj *proj, int x)
{
	int	y;

	y = WIN_HEIGHT - 1;
	while (y > proj->wall_bot_pxl)
	{
		my_pixel_put(main_img, x, y, map->color_f);
		y--;
	}
}

void	render_textures(t_data *data)
{
	t_proj	proj;
	int		x;
	int		y;

	x = 0;
	y = 0;
	ft_memset(&proj, 0, sizeof(t_proj));
	while (x < WIN_WIDHT)
	{
		get_proj_info(&proj, data, x);
		drawn_ceiling(&data->main_img, &data->map, &proj, x);
		while (y < proj.wall_bot_pxl)
		{
			y++;
		}
		drawn_floor(&data->main_img, &data->map, &proj, x);
		y = 0;
		x++;
	}
}
