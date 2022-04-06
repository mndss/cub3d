/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:00:42 by guferrei          #+#    #+#             */
/*   Updated: 2022/04/06 18:06:55 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	compare_hits(t_dist *horz, t_dist *vert, t_rays *ray)
{
	if (vert->dist < horz->dist)
	{
		ray->wall_hit_x = vert->x;
		ray->wall_hit_y = vert->y;
		ray->distance = vert->dist;
	}
	else
	{
		ray->wall_hit_x = horz->x;
		ray->wall_hit_y = horz->y;
		ray->distance = horz->dist;
	}
}

int	cast_ray(t_rays *ray, t_player *player, char **map)
{
	t_dist	horz;
	t_dist	vert;

	horz.x = 0;
	horz.y = 0;
	horz.dist = 0;
	init_ray(ray);
	horz_hit(&horz, ray, player, map);
	vert_hit(&vert, ray, player, map);
	compare_hits(&horz, &vert, ray);
	return (0);
}
