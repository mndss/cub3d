/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:00:42 by guferrei          #+#    #+#             */
/*   Updated: 2022/04/06 15:30:59 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	horz_hit(t_dist *horz, t_rays *ray, t_player *player, char **map)
{
	t_cord	intercept;
	t_cord	step;
	t_cord	next_hit;
	bool	found_hit;

	found_hit = false;
	intercept.y = floor(player->y / TILE_SIZE) * TILE_SIZE;
	if (ray->is_down)
		intercept.y += TILE_SIZE;
	intercept.x = player->x + (intercept.y - player->y) / tan(ray->ray_angle);
	step.y = TILE_SIZE;
	if (ray->is_up)
		step.y *= -1;
	step.x = TILE_SIZE / tan(ray->ray_angle);
	if ((ray->is_left && step.x > 0) || (ray->is_right && step.x < 0))
		step.x *= -1;
	next_hit.x = intercept.x;
	next_hit.y = intercept.y;
	printf("HORZ\nxstep %d\nystep %d\nxintercept %d\nyintercept %d\n", step.x, step.y, intercept.x, intercept.y);
	while (next_hit.x >= 0 && next_hit.x <= 8 * TILE_SIZE
			&& next_hit.y >= 0 && next_hit.y <= 8 * TILE_SIZE
	)
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

void vert_hit(t_dist *vert, t_rays *ray, t_player *player, char **map)
{
	t_cord intercept;
	t_cord step;
	t_cord next_hit;
	bool found_hit;

	found_hit = false;
	intercept.x = floor(player->x / TILE_SIZE) * TILE_SIZE;
	if (ray->is_right)
		intercept.x += TILE_SIZE;
	intercept.y = player->y + (intercept.x - player->x) * tan(ray->ray_angle);
	step.x = TILE_SIZE;
	if (ray->is_left)
		step.x *= -1;
	step.y = TILE_SIZE * tan(ray->ray_angle);
	if ((ray->is_up && step.y > 0 ) || (ray->is_down && step.y < 0))
		step.y *= -1;
	next_hit.x = intercept.x;
	next_hit.y = intercept.y;
	printf("VERT\nxstep %d\nystep %d\nxintercept %d\nyintercept %d\n", step.x, step.y, intercept.x, intercept.y);
	while (next_hit.x >= 0 && next_hit.x <= 8 * TILE_SIZE
			&& next_hit.y >= 0 && next_hit.y <= 8 * TILE_SIZE
	)
	{
		if (is_wall(&next_hit, false, ray->is_left, map))
		{
			found_hit = true;
			vert->x = next_hit.x;
			vert->y = next_hit.y;
			break ;
		}
		else {
			next_hit.x += step.x;
			next_hit.y += step.y;
		}
	}
	if (found_hit)
		vert->dist = find_distance(player->x, player->y,
			vert->x, vert->y);
	else
		vert->dist = MAX_INT;
	return ;
}

void	compare_hits(t_dist *horz, t_dist *vert, t_rays *ray)
{
	if (vert->dist < horz->dist)
	{
		printf("Is vert\n");
		ray->wall_hit_x = vert->x;
		ray->wall_hit_y = vert->y;
		ray->distance = vert->dist;
	}
	else
	{
		printf("Is horz\n");
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
	//FZR OS CÁLCULO TUDO
	return (0);
}
