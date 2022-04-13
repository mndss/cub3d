/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_listener.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:51:39 by elima-me          #+#    #+#             */
/*   Updated: 2022/04/13 20:48:24 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	player_walk(t_data *data)
{
	float	aux_x;
	float	aux_y;

	aux_x = data->player.x + (cos(data->player.direction) \
			* (data->player.walk_direction * (TILE_SIZE / 16))) \
			+ (cos((data->player.direction) - (PI / 2)) \
			* (data->player.side_walk * (TILE_SIZE / 16)));
	aux_y = data->player.y + (sin(data->player.direction) \
			* (data->player.walk_direction * (TILE_SIZE / 16))) \
			+ (sin((data->player.direction) - (PI / 2)) \
			* (data->player.side_walk * (TILE_SIZE / 16)));
	if (data->map.map[((int)aux_y + 5) / TILE_SIZE] \
		[((int)aux_x + 5) / TILE_SIZE] == '1'
		|| data->map.map[((int)aux_y - 5) / TILE_SIZE] \
		[((int)aux_x - 5) / TILE_SIZE] == '1')
		return (1);
	data->player.x = aux_x;
	data->player.y = aux_y;
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == LEFT_ARROW)
		data->player.turn_direction = +1;
	if (keycode == RIGHT_ARROW)
		data->player.turn_direction = -1;
	if (keycode == KEY_W)
		data->player.walk_direction = +1;
	if (keycode == KEY_S)
		data->player.walk_direction = -1;
	if (keycode == KEY_A)
		data->player.side_walk = +1;
	if (keycode == KEY_D)
		data->player.side_walk = -1;
	if (keycode == ESC)
		close_game(data);
	data->player.direction += data->player.turn_direction * (PI / 180 * 2);
	find_facing_direction(&data->player);
	if (!player_walk(data))
	{
		create_rays(data);
		render_walls(data);
	}
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == LEFT_ARROW || keycode == RIGHT_ARROW)
		data->player.turn_direction = 0;
	if (keycode == KEY_W || keycode == KEY_S)
		data->player.walk_direction = 0;
	if (keycode == KEY_A)
		data->player.side_walk = 0;
	if (keycode == KEY_D)
		data->player.side_walk = 0;
	return (0);
}
