/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:46:27 by elima-me          #+#    #+#             */
/*   Updated: 2022/04/07 14:47:01 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	create_images(t_map_info *map_info)
{
	// void	*mlx_ptr;
	// void	*paths[4];
	// int		x;
	// int		y;
	// int		i;

	// i = 0;
	// mlx_ptr = mlx_init();
	// paths[0] = mlx_xpm_file_to_image(mlx_ptr, map_info->no, &x, &y);
	// paths[1] = mlx_xpm_file_to_image(mlx_ptr, map_info->so, &x, &y);
	// paths[2] = mlx_xpm_file_to_image(mlx_ptr, map_info->we, &x, &y);
	// paths[3] = mlx_xpm_file_to_image(mlx_ptr, map_info->ea, &x, &y);
	// while (i < 4)
	// {
	// 	mlx_destroy_image(mlx_ptr, paths[i]);
	// 	i++;
	// }
	// free(paths);
	// mlx_destroy_display(mlx_ptr);
	// free(mlx_ptr);
	(void)map_info;
	return (0);
}
