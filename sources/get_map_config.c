/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:16:30 by elima-me          #+#    #+#             */
/*   Updated: 2022/04/01 16:15:01 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	*get_textures(char *prefix, char **map)
{
	int		count;
	char	*path;
	char	**temp;

	count = 0;
	while (count < 6)
	{
		if (!ft_strncmp(prefix, map[count], 2))
		{
			temp = ft_split(map[count], ' ');
			if (!temp[1] || temp[2])
			{
				free_matrix(temp);
				return (NULL);
			}
			path = ft_strdup(temp[1]);
			free_matrix(temp);
			return (path);
		}
		count++;
	}
	return (NULL);
}

char	*get_colors(char prefix, char **map)
{
	int		count;
	char	*values;

	count = 0;
	while (count < 6)
	{
		if (!ft_strncmp(&prefix, map[count], 1))
		{
			values = ft_strdup(map[count] + 1);
			return (values);
		}
		count++;
	}
	return (NULL);
}

void	get_info(char **map, t_map_info *map_info, int map_size)
{
	map_info->no = get_textures("NO", map);
	map_info->so = get_textures("SO", map);
	map_info->we = get_textures("WE", map);
	map_info->ea = get_textures("EA", map);
	map_info->f = get_colors('F', map);
	map_info->c = get_colors('C', map);
	get_map(map, map_info, map_size);
	map_info->color_f = set_colors(map_info->f);
	map_info->color_c = set_colors(map_info->c);
}
