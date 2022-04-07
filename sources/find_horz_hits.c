/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_horz_hits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:06:30 by elima-me          #+#    #+#             */
/*   Updated: 2022/04/07 17:23:22 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	find_intercept_horz(t_cord *intercept, t_rays *ray,
			t_player *player)
{
	intercept->y = floor(player->y / TILE_SIZE) * TILE_SIZE;
	if (ray->is_down)
		intercept->y += TILE_SIZE;
	intercept->x = player->x + (intercept->y - player->y) / tan(ray->ray_angle);
}

static void	find_step_horz(t_cord *step, t_rays *ray)
{
	step->y = TILE_SIZE;
	if (ray->is_up)
		step->y *= -1;
	step->x = TILE_SIZE / tan(ray->ray_angle);
	if ((ray->is_left && step->x > 0) || (ray->is_right && step->x < 0))
		step->x *= -1;
}

static int	find_wall_horz(t_rays *ray, t_hits *hits, char **map, t_dist *horz)
{
	while (hits->next_hit.x >= 0 && hits->next_hit.x <= 7 * TILE_SIZE
		&& hits->next_hit.y >= 0 && hits->next_hit.y <= 7 * TILE_SIZE
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
	t_hits	hits_horz;

	horz->dist = (float)MAX_INT;
	find_intercept_horz(&hits_horz.intercept, ray, player);
	find_step_horz(&hits_horz.step, ray);
	hits_horz.next_hit.x = hits_horz.intercept.x;
	hits_horz.next_hit.y = hits_horz.intercept.y;
	if (find_wall_horz(ray, &hits_horz, map, horz))
		horz->dist = find_distance(player->x,
				player->y, horz->x, horz->y);
}
