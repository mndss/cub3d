/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:57:10 by elima-me          #+#    #+#             */
/*   Updated: 2022/04/12 17:00:27 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	start_game(t_data *data)
{
	data->win = mlx_new_window(data->mlx, WIN_WIDHT, WIN_HEIGHT, "CUB3D");
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	ft_memset(&data, '\0', sizeof(t_data));
	data.mlx = mlx_init();
	if (ft_setup(argc, argv, &data))
	{
		ft_clean(&data.map);
		return (1);
	}
	game_config(&data);
	create_rays(&data);
	start_game(&data);
	render_walls(&data);
	ft_clean(&data.map);
	return (0);
}
