/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:57:10 by elima-me          #+#    #+#             */
/*   Updated: 2022/03/31 15:44:50 by guferrei         ###   ########.fr       */
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
	t_map_info	map_info;

	ft_setup(argc, argv, &map_info);
	ft_clean(&map_info);
	return (0);
}
