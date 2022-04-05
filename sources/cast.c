/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:00:42 by guferrei          #+#    #+#             */
/*   Updated: 2022/04/05 15:59:30 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	horz_hit(t_dist *horz, t_rays *ray, t_player *player, char **map)
{
	t_cord	intercept;
	t_cord	step;
	t_cord	next_hit;
	bool	found_hit;

	intercept.y = floor(player->y / TILE_SIZE) * TILE_SIZE;
	if (ray->is_down)
		intercept.y += TILE_SIZE;
	intercept.x = player->x + (intercept.y - player->y)
		/ tan(ray->ray_angle);
	step.y = TILE_SIZE;
	if (ray->is_up)
		step.y *= -1;
	step.x = TILE_SIZE / tan(ray->ray_angle);
	if (ray->is_left && step.x > 0)
		step.x *= -1;
	if (ray->is_right && step.x < 0)
		player->y;
	next_hit.x = intercept.x;
	next_hit.y = intercept.y;
	while (next_hit.x >= 0 && next_hit.x <= WIN_WIDHT
		&& next_hit.y >= 0 && next_hit.y <= WIN_HEIGHT)
	{
		if (is_wall(&next_hit, ray->is_up, false, map))
		{
			found_hit = true;
			horz->x = next_hit.x;
			horz->y = next_hit.y;
			break ;
		}
		else
		{
			next_hit.y += step.y;
			next_hit.x += step.x;
		}
	}
	if (found_hit)
		horz->dist = find_distance(player->x,
				player->y, horz->x, horz->y);
	else
		horz->dist = MAX_INT;
	return ;
}

int	cast_ray(t_rays *ray, t_player *player, char **map)
{
	t_dist	horz;
	t_dist	vert;

	init_ray(ray);
	horz_hit(&horz, ray, player, map);
	//FZR OS CÁLCULO TUDO
}
