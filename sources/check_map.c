/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:56:00 by guferrei          #+#    #+#             */
/*   Updated: 2022/04/01 16:11:38 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_direction(char direction)
{
	if (direction && direction != ' ')
		return (0);
	return (1);
}

int	check_arround(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == ' ')
		return (0);
	if ((map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
		|| map[y][x] == 'W' || map[y][x] == 'E') && y > 0 && map[y + 1])
	{
		if (check_direction(map[y - 1][x])
			|| check_direction(map[y + 1][x])
			|| check_direction(map[y][x + 1])
			|| check_direction(map[y][x - 1])
			|| check_direction(map[y - 1][x - 1])
			|| check_direction(map[y - 1][x + 1])
			|| check_direction(map[y + 1][x - 1])
			|| check_direction(map[y + 1][x + 1]))
			return (1);
		return (0);
	}
	return (1);
}

float	find_direction(char direction)
{
	if (direction == 'N')
		return (PI * 1.5);
	if (direction == 'S')
		return (PI / 2.0);
	if (direction == 'W')
		return (PI);
	else
		return (0);
}

int	check_player(char cord, int y, int x, t_player *player)
{
	if (cord == 'N' || cord == 'S' || cord == 'W' || cord == 'E')
	{
		if (player->x)
			return (1);
		player->y = y;
		player->x = x;
		player->direction = find_direction(cord);
	}
	return (0);
}

int	check_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map.map[y])
	{
		while (data->map.map[y][x])
		{
			if (check_player(data->map.map[y][x], y, x, &data->player))
				return (print_err(ERR_DOUBLE_PLAYER));
			if (check_arround(data->map.map, x, y))
				return (print_err(ERR_INVALID_MAP));
			x++;
		}
		x = 0;
		y++;
	}
	if (!data->player.x)
		return (print_err(ERR_NO_PLAYER));
	return (0);
}
