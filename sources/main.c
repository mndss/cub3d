/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:57:10 by elima-me          #+#    #+#             */
/*   Updated: 2022/04/07 17:09:35 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int argc, char *argv[])
{
	t_data	data;

	ft_memset(&data, '\0', sizeof(t_data));
	if (ft_setup(argc, argv, &data))
	{
		ft_clean(&data.map);
		return (1);
	}
	game_config(&data);
	create_rays(&data);
	//render_walls(&data);
	ft_clean(&data.map);
	return (0);
}
