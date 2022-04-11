/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_listener.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:51:39 by elima-me          #+#    #+#             */
/*   Updated: 2022/04/11 17:44:45 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	player_walk(t_data *data)
{
	float	aux_x;
	float	aux_y;

	aux_x = data->player.x + (cos(data->player.direction) * data->player.walk_direction);
	aux_y = data->player.y + (sin(data->player.direction) * data->player.walk_direction);
	if (data->map.map[(int)aux_y / TILE_SIZE][(int)aux_x / TILE_SIZE] == '1')
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
	data->player.direction += data->player.turn_direction * (PI / 180 * 2);
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
	return (0);
}


//W 119 S 115