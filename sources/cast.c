/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:00:42 by guferrei          #+#    #+#             */
/*   Updated: 2022/04/06 20:13:34 by elima-me         ###   ########.fr       */
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
	vert.x = 0;
	vert.y = 0;
	vert.dist = 0;
	init_ray(ray);
	horz_hit(&horz, ray, player, map);
	vert_hit(&vert, ray, player, map);
	compare_hits(&horz, &vert, ray);
	return (0);
}

void	create_rays(t_data *data)
{
	float	angle_step;
	int		count;
	float	inital_angle;

	count = 0;
	angle_step = data->fov_angle / WIN_WIDHT;
	inital_angle = (data->player.direction - data->fov_angle / 2);
	data->player.x = 128;
	data->player.y = 128;
	while (count < WIN_WIDHT)
	{
		data->rays[count].ray_angle = inital_angle + angle_step * count;
		cast_ray(&data->rays[count], &data->player, data->map.map);
		count++;
	}
	printf("FIRST RAY DISTANCE: %d\n", data->rays[0].distance);
	printf("LAST RAY DISTANCE: %d\n", data->rays[WIN_WIDHT - 1].distance);
}