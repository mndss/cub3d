/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_listener.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:51:39 by elima-me          #+#    #+#             */
/*   Updated: 2022/04/11 15:51:47 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	key_press(int keycode, t_data *data)
{
	if (keycode == LEFT_ARROW)
		data->player.turn_direction = +1;
	if (keycode == RIGHT_ARROW)
		data->player.turn_direction = -1;
	data->player.direction += data->player.turn_direction * (PI / 180 * 2);
	create_rays(data);
	render_walls(data);
	if (keycode == RIGHT_ARROW || keycode == LEFT_ARROW)
		printf("%d\n", keycode);
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == LEFT_ARROW || keycode == RIGHT_ARROW)
		data->player.turn_direction = 0;
	printf("%c\n", keycode);
	return (0);
}
