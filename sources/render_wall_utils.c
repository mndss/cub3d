/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:46:40 by elima-me          #+#    #+#             */
/*   Updated: 2022/04/12 19:57:41 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

__uint32_t	get_hited_texture(t_rays *ray,
	t_proj *proj, t_img *textures)
{
	if (ray->hit_vert == true)
	{
		if (ray->ray_angle > (PI / 2) && ray->ray_angle < (PI * 1.5))
			return (textures->we.buffer[(TILE_SIZE
						* proj->offset_y) + proj->offset_x]);
		else
			return (textures->ea.buffer[(TILE_SIZE
						* proj->offset_y) + proj->offset_x]);
	}
	else
	{
		if (ray->ray_angle > PI)
			return (textures->no.buffer[(TILE_SIZE
						* proj->offset_y) + proj->offset_x]);
		else
			return (textures->so.buffer[(TILE_SIZE
						* proj->offset_y) + proj->offset_x]);
	}
}

void	draw_walls(t_proj *proj, t_data *data, int x, int y)
{
	proj->dst_from_top = y + (proj->wall_strip_height / 2)
		- (WIN_HEIGHT / 2);
	proj->offset_y = proj->dst_from_top
		* ((float)TILE_SIZE / proj->wall_strip_height);
	proj->color = get_hited_texture(&data->rays[x],
			proj, &data->textures);
	my_pixel_put(&data->main_img, x, y, proj->color);
}

void	drawn_ceiling(t_img_addr *main_img,
		t_map_info *map, t_proj *proj, int x)
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
