/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:00:42 by guferrei          #+#    #+#             */
/*   Updated: 2022/04/11 20:39:45 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	compare_hits(t_dist *horz, t_dist *vert, t_rays *ray)
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

static int	find_wall_height(t_rays *ray, t_data *data)
{
	float	dst_proj_plane;
	float	fix_wall_height;

	fix_wall_height = ray->distance \
		* cos(ray->ray_angle - data->player.direction);
	dst_proj_plane = (WIN_WIDHT / 2) / tan(data->fov_angle / 2);
	ray->wall_height = (TILE_SIZE / fix_wall_height) * dst_proj_plane;
	return (0);
}

static int	cast_ray(t_rays *ray, t_data *data)
{
	t_dist	horz;
	t_dist	vert;

	ft_memset(&horz, '\0', sizeof(t_dist));
	ft_memset(&vert, '\0', sizeof(t_dist));
	init_ray(ray);
	horz_hit(&horz, ray, data);
	vert_hit(&vert, ray, data);
	compare_hits(&horz, &vert, ray);
	find_wall_height(ray, data);
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
	while (count < WIN_WIDHT)
	{
		data->rays[count].ray_angle = inital_angle + angle_step * count;
		cast_ray(&data->rays[count], data);
		count++;
	}
}
