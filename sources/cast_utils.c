/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:57:29 by guferrei          #+#    #+#             */
/*   Updated: 2022/04/05 19:52:49 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

float	normalize_angle(float angle)
{
	angle = remainderf(angle, (2 * PI));
	if (angle < 0)
		angle += (2 * PI);
	return (angle);
}

void	init_ray(t_rays *ray)
{
	ray->ray_angle = normalize_angle(ray->ray_angle);
	ray->is_down = (ray->ray_angle > 0 && ray->ray_angle < PI);
	ray->is_up = !ray->is_down;
	ray->is_right = (ray->ray_angle < 0.5 * PI
			|| ray->ray_angle > 1.5 * PI);
	ray->is_left = !ray->is_right;
}

bool	is_wall(t_cord *hit, bool up, bool left, char **map)
{
	int	x;
	int	y;
	int	auxx;
	int	auxy;

	if (up)
	{
		auxy = hit->y - 1;
		auxx = hit->x;
	}
	if (left)
	{
		auxx = hit->x - 1;
		auxy = hit->y;
	}
	x = floor(auxx / TILE_SIZE);
	y = floor(auxy / TILE_SIZE);
	if (map[y][x] == '0')
		return (0);
	else
		return (1);
}

int	find_distance(int px, int py, int wx, int wy)
{
	int	dist;

	dist = sqrt((wx - px) * (wx - px) + (wy - py) * (wy - py));
	return (dist);
}
