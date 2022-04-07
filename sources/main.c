/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:57:10 by elima-me          #+#    #+#             */
/*   Updated: 2022/04/07 14:59:41 by elima-me         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_data	data;

	ft_setup(argc, argv, &data);
	game_config(&data);
	create_rays(&data);
	render_walls(&data);
	ft_clean(&data.map);
	return (0);
}
