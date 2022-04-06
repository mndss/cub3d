/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_horz_hits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:06:30 by elima-me          #+#    #+#             */
/*   Updated: 2022/04/06 18:44:26 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	find_intercept_horz(t_cord *intercept, t_rays *ray, t_player *player)
{
	intercept->y = floor(player->y / TILE_SIZE) * TILE_SIZE;
	if (ray->is_down)
		intercept->y += TILE_SIZE;
	intercept->x = player->x + (intercept->y - player->y) / \
		tan(ray->ray_angle);
}

void	find_step_horz(t_cord *step, t_rays *ray)
{
	step->y = TILE_SIZE;
	if (ray->is_up)
		step->y *= -1;
	step->x = TILE_SIZE / tan(ray->ray_angle);
	if ((ray->is_left && step->x > 0) || (ray->is_right && step->x < 0))
		step->x *= -1;
}

int	find_wall_horz(t_rays *ray, t_hits *hits, char **map, t_dist *horz)
{
	while (hits->next_hit.x >= 0 && hits->next_hit.x <= 8 * TILE_SIZE
		&& hits->next_hit.y >= 0 && hits->next_hit.y <= 8 * TILE_SIZE
	)
	{
		if (is_wall(&hits->next_hit, ray->is_up, false, map))
		{
			horz->x = hits->next_hit.x;
			horz->y = hits->next_hit.y;
			return (1);
		}
		else
		{
			hits->next_hit.y += hits->step.y;
			hits->next_hit.x += hits->step.x;
		}
	}
	return (0);
}

void	horz_hit(t_dist *horz, t_rays *ray, t_player *player, char **map)
{
	t_hits	hits;

	horz->dist = MAX_INT;
	find_intercept_horz(&hits.intercept, ray, player);
	find_step_horz(&hits.step, ray);
	hits.next_hit.x = hits.intercept.x;
	hits.next_hit.y = hits.intercept.y;
	if (find_wall_horz(ray, &hits, map, horz))
		horz->dist = find_distance(player->x,
				player->y, horz->x, horz->y);
}
