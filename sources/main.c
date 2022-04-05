/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:57:10 by elima-me          #+#    #+#             */
/*   Updated: 2022/04/05 17:25:24 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_clean(t_map_info *map)
{
	free_matrix(map->map);
	free(map->no);
	free(map->so);
	free(map->we);
	free(map->ea);
	free(map->f);
	free(map->c);
}

int main(void)
{
	t_rays ray;
	t_player player;
	char map[9][9] ={
		"11111111",
        "10100101",
		"10100101",
        "10000101",
    	"10000001",
        "10100001",
        "10100011",
        "11111111"
	};

	ft_memset(&ray, '\0', sizeof(t_rays));
	ft_memset(&player, '\0', sizeof(t_player));
	ray.ray_angle = PI / 3; 
	player.x = 128;
	player.y = 128;
	cast_ray(&ray, &player, (char **)map);
	printf("Hit x: %d\nHit y: %d\nDistance: %d", ray.wall_hit_x, ray.wall_hit_y, ray.distance);
}

// int	main(int argc, char *argv[])
// {
// 	t_data	data;

// 	ft_setup(argc, argv, &data);
// 	game_config(&data);
// 	ft_clean(&data.map);
// 	return (0);
// }
