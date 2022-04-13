/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:09:23 by guferrei          #+#    #+#             */
/*   Updated: 2022/04/12 20:38:22 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_n_null(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	free_matrix(char **ptr)
{
	int	count;

	count = 0;
	while (ptr[count])
	{
		free_n_null(ptr[count]);
		count++;
	}
	free_n_null(ptr);
}

void	ft_clean(t_map_info *map, t_data *data)
{
	if (map->map)
		free_matrix(map->map);
	free_n_null(map->no);
	free_n_null(map->so);
	free_n_null(map->we);
	free_n_null(map->ea);
	free_n_null(map->f);
	free_n_null(map->c);
	free_n_null(data->textures.no.buffer);
	free_n_null(data->textures.so.buffer);
	free_n_null(data->textures.we.buffer);
	free_n_null(data->textures.ea.buffer);
}
