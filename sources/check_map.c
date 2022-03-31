/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:56:00 by guferrei          #+#    #+#             */
/*   Updated: 2022/03/31 15:42:54 by guferrei         ###   ########.fr       */
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
		|| map[y][x] == 'W' || map[y][x] == 'E') && y > 0)
	{
		if (check_direction(map[y - 1][x]) || check_direction(map[y + 1][x])
			|| check_direction(map[y][x + 1]) || check_direction(map[y][x - 1])
			|| check_direction(map[y - 1][x - 1]) || check_direction(map[y - 1][x + 1])
			|| check_direction(map[y + 1][x - 1]) || check_direction(map[y + 1][x + 1]))
		{
			printf("map[%d][%d] ERRO! MAPA INVÁLIDO\n", y, x);
			return (1);
		}
		return (0);
	}
	else
	{
		printf("%c ERRO! CARACTER INVÁLIDO\n", map[y][x]);
		return (1);
	}
}

int	check_map(char **map)
{
	int	x;
	int	y;
	int	p;

	x = 0;
	y = 0;
	p = 0;
	while(map[y])
	{
		while(map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W' || map[y][x] == 'E')
			{
				if (p > 0)
				{
					printf("map[%d][%d] ERRO! PLAYER DUPLICADO\n", y, x);
					return (1);
				}
				p++;
				//GUARDA POSIÇÃO PLAYER;
			}
			if (check_arround(map, x, y))
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	if (p == 0)
	{
		printf("ERRO! SEM PLAYER\n");
		return (1);
	}
	printf("SUCESSO!!\n");
	return (0);
}

//0 || N, S, W, E -> *PTR && !' '           <- 0 ->
//
//ptr[y][x] -> ptr[y - 1][x] ...

