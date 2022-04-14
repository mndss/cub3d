/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:57:10 by elima-me          #+#    #+#             */
/*   Updated: 2022/04/13 21:20:06 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	close_game(t_data *data)
{
	ft_clean(&data->map, data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (1);
}

void	start_game(t_data *data)
{
	data->win = mlx_new_window(data->mlx, WIN_WIDHT, WIN_HEIGHT, "CUB3D");
	render_walls(data);
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	mlx_hook(data->win, 17, 0L, close_game, data);
	mlx_expose_hook(data->win, render_walls, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	ft_memset(&data, '\0', sizeof(t_data));
	data.mlx = mlx_init();
	if (ft_setup(argc, argv, &data))
	{
		close_game(&data);
		return (1);
	}
	create_rays(&data);
	start_game(&data);
	render_walls(&data);
	ft_clean(&data.map, &data);
	return (0);
}
