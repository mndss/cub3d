/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:50:58 by guferrei          #+#    #+#             */
/*   Updated: 2022/04/12 19:48:46 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	get_proj_info(t_proj *proj, t_data *data, int x)
{
	proj->dist_persp = data->rays[x].distance
		* cos(data->rays[x].ray_angle - data->player.direction);
	proj->wall_height_proj = (TILE_SIZE / proj->dist_persp)
		* ((WIN_WIDHT / 2) / tan(data->fov_angle / 2));
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

void	find_facing_direction(t_player *player)
{
	float	aux_angle;

	aux_angle = normalize_angle(player->direction);
	if (aux_angle > PI)
		player->is_facing_up = true;
	else
		player->is_facing_up = false;
	if (aux_angle > (PI / 2) && aux_angle < (PI * 1.5))
		player->is_facing_left = true;
	else
		player->is_facing_left = false;
}

void	fix_offsetx(t_rays *ray, int *offset_x)
{
	if (ray->hit_vert == false && ray->ray_angle < PI)
		*offset_x = TILE_SIZE - *offset_x;
	if (ray->hit_vert == true && ray->ray_angle > (PI / 2)
		&& ray->ray_angle < (PI * 1.5))
		*offset_x = TILE_SIZE - *offset_x;
}

void	get_text_offsetx(t_data *data, t_proj *proj, int x)
{
	if (data->rays[x].hit_vert == true)
		proj->offset_x = (int)data->rays[x].wall_hit_y % TILE_SIZE;
	else
		proj->offset_x = (int)data->rays[x].wall_hit_x % TILE_SIZE;
	fix_offsetx(&data->rays[x], &proj->offset_x);
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
		get_text_offsetx(data, &proj, x);
		y = proj.wall_top_pxl;
		while (y < proj.wall_bot_pxl)
		{
			draw_walls(&proj, data, x, y);
			y++;
		}
		drawn_floor(&data->main_img, &data->map, &proj, x);
		x++;
	}
}
