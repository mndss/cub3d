/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:46:50 by guferrei          #+#    #+#             */
/*   Updated: 2022/04/13 20:45:08 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

unsigned int	get_color_pxl(t_img_addr *img, int x, int y)
{
	char	*color;

	color = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)color);
}

static int	check_invalid_color(char *color)
{
	char	*aux;

	aux = ft_strtrim(color, " ");
	if (is_invalid_decimal(color))
		return (1);
	if (ft_strlen(aux) > 0 && ft_strlen(aux) <= 3)
	{
		free(aux);
		return (0);
	}
	free(aux);
	return (1);
}

static int	rgb_to_decimal(char **colors)
{
	int	r;
	int	g;
	int	b;

	if (check_invalid_color(colors[0]) || check_invalid_color(colors[1])
		|| check_invalid_color(colors[2]))
		return (-1);
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
			if (char_occurrence(values, ',') != 2)
			{
				free(values);
				return (NULL);
			}
			return (values);
		}
		count++;
	}
	return (NULL);
}
