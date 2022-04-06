/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_vert_hits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:42:10 by elima-me          #+#    #+#             */
/*   Updated: 2022/04/06 16:05:51 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	find_intercept_vert(t_cord *intercept, t_rays *ray, t_player *player)
{
	intercept->x = floor(player->x / TILE_SIZE) * TILE_SIZE;
	if (ray->is_right)
		intercept->x += TILE_SIZE;
	intercept->y = player->y + (intercept->x - player->x) * tan(ray->ray_angle);
}

void	find_step_vert(t_cord *step, t_rays *ray)
{
	step->x = TILE_SIZE;
	if (ray->is_left)
		step->x *= -1;
	step->y = TILE_SIZE * tan(ray->ray_angle);
	if ((ray->is_up && step->y > 0) || (ray->is_down && step->y < 0))
		step->y *= -1;
}

void	vert_hit(t_dist *vert, t_rays *ray, t_player *player, char **map)
{
	t_cord	intercept;
	t_cord	step;
	t_cord	next_hit;

	vert->dist = MAX_INT;
	next_hit.x = intercept.x;
	next_hit.y = intercept.y;
	while (next_hit.x >= 0 && next_hit.x <= 8 * TILE_SIZE
		&& next_hit.y >= 0 && next_hit.y <= 8 * TILE_SIZE
	)
	{
		if (is_wall(&next_hit, false, ray->is_left, map))
		{
			vert->x = next_hit.x;
			vert->y = next_hit.y;
			vert->dist = find_distance(player->x, player->y,
					vert->x, vert->y);
			break ;
		}
		else
		{
			next_hit.x += step.x;
			next_hit.y += step.y;
		}
	}
}
