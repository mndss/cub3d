/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_vert_hits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:42:10 by elima-me          #+#    #+#             */
/*   Updated: 2022/04/06 19:53:12 by elima-me         ###   ########.fr       */
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

int	find_wall_vert(t_rays *ray, t_hits *hits, char **map, t_dist *vert)
{
	while (hits->next_hit.x >= 0 && hits->next_hit.x <= 7 * TILE_SIZE
		&& hits->next_hit.y >= 0 && hits->next_hit.y <= 7 * TILE_SIZE
	)
	{
		if (is_wall(&hits->next_hit, false, ray->is_left, map))
		{
			vert->x = hits->next_hit.x;
			vert->y = hits->next_hit.y;
			return (1) ;
		}
		else
		{
			hits->next_hit.x += hits->step.x;
			hits->next_hit.y += hits->step.y;
		}
	}
	return (0);
}

void	vert_hit(t_dist *vert, t_rays *ray, t_player *player, char **map)
{
	t_hits	hits_vert;

	vert->dist = MAX_INT;
	find_intercept_vert(&hits_vert.intercept, ray, player);
	find_step_vert(&hits_vert.step, ray);
	hits_vert.next_hit.x = hits_vert.intercept.x;
	hits_vert.next_hit.y = hits_vert.intercept.y;
	if (find_wall_vert(ray, &hits_vert, map, vert))
		vert->dist = find_distance(player->x, player->y,
				vert->x, vert->y);
}
