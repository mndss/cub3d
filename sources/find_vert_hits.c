/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_vert_hits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:42:10 by elima-me          #+#    #+#             */
/*   Updated: 2022/04/11 21:12:06 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	find_intercept_vert(t_cord *intercept, t_rays *ray,
			t_player *player)
{
	intercept->x = floor(player->x / TILE_SIZE) * TILE_SIZE;
	if (ray->is_right)
		intercept->x += TILE_SIZE;
	intercept->y = player->y + (intercept->x - player->x) * tan(ray->ray_angle);
}

static void	find_step_vert(t_cord *step, t_rays *ray)
{
	step->x = TILE_SIZE;
	if (ray->is_left)
		step->x *= -1;
	step->y = TILE_SIZE * tan(ray->ray_angle);
	if ((ray->is_up && step->y > 0) || (ray->is_down && step->y < 0))
		step->y *= -1;
}

static int	find_wall_vert(t_rays *ray, t_hits *hits, t_data *data,
			t_dist *vert)
{
	while (hits->next_hit.x >= 0
		&& hits->next_hit.x <= data->map.n_cols * TILE_SIZE
		&& hits->next_hit.y >= 0
		&& hits->next_hit.y <= data->map.n_lines * TILE_SIZE
	)
	{
		if (is_wall(&hits->next_hit, false, ray->is_left, data->map.map))
		{
			vert->x = hits->next_hit.x;
			vert->y = hits->next_hit.y;
			return (1);
		}
		else
		{
			hits->next_hit.x += hits->step.x;
			hits->next_hit.y += hits->step.y;
		}
	}
	return (0);
}

void	vert_hit(t_dist *vert, t_rays *ray, t_data *data)
{
	t_hits	hits_vert;

	vert->dist = (float)MAX_INT;
	find_intercept_vert(&hits_vert.intercept, ray, &data->player);
	find_step_vert(&hits_vert.step, ray);
	hits_vert.next_hit.x = hits_vert.intercept.x;
	hits_vert.next_hit.y = hits_vert.intercept.y;
	if (find_wall_vert(ray, &hits_vert, data, vert))
		vert->dist = find_distance(data->player.x, data->player.y,
				vert->x, vert->y);
}
