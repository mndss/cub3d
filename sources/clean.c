/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:09:23 by guferrei          #+#    #+#             */
/*   Updated: 2022/04/07 17:10:51 by guferrei         ###   ########.fr       */
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

void	ft_clean(t_map_info *map)
{
	if (map->map)
		free_matrix(map->map);
	free_n_null(map->no);
	free_n_null(map->so);
	free_n_null(map->we);
	free_n_null(map->ea);
	free_n_null(map->f);
	free_n_null(map->c);
}
