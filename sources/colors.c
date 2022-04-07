/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:46:50 by guferrei          #+#    #+#             */
/*   Updated: 2022/04/07 17:19:22 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	rgb_to_decimal(char **colors)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	if ((r > 255 || r < 0) || (g > 255 || g < 0) || (b > 255 || b < 0))
		return (-1);
	return (r * 65536 + g * 256 + b);
}

int	set_colors(char *str_color)
{
	char	**colors;
	int		dec_color;
	int		i;

	i = 0;
	if (!str_color)
		return (-1);
	colors = ft_split(str_color, ',');
	while (colors[i])
		i++;
	if (i != 3)
	{
		free_matrix(colors);
		return (-1);
	}
	dec_color = rgb_to_decimal(colors);
	free_matrix(colors);
	return (dec_color);
}

char	*get_colors(char *prefix, char **map)
{
	int		count;
	char	*values;

	count = 0;
	while (count < 6)
	{
		if (!ft_strncmp(prefix, map[count], 1))
		{
			values = ft_strdup(map[count] + 1);
			return (values);
		}
		count++;
	}
	return (NULL);
}
