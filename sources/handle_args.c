/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:26:33 by guferrei          #+#    #+#             */
/*   Updated: 2022/04/12 16:48:57 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	invalid_args(int argc, const char *map)
{
	if (argc != 2)
		return (print_err(ERR_ARGS));
	if (ft_strncmp(&map[strlen(map) - 4], ".cub", ft_strlen(map)))
		return (print_err(ERR_INVALID_EXT));
	return (0);
}

static int	check_map_info(t_data *data)
{
	if (!*data->map.map)
		return (print_err(ERR_INVALID_MAP));
	if (data->map.color_c == -1 || data->map.color_f == -1)
		return (print_err(ERR_INVALID_COLOR));
	if (check_map(data))
		return (1);
	return (0);
}

int	ft_setup(int argc, char *argv[], t_data *data)
{
	int		n_lines;
	char	**map;

	if (invalid_args(argc, argv[1]))
		return (1);
	n_lines = count_lines(argv[1]);
	if (n_lines < 0)
		return (print_err(ERR_NOT_FOUND));
	if (n_lines < 9)
		return (print_err(ERR_INVALID_MAP));
	map = read_map(argv[1], n_lines);
	get_info(map, &data->map, (n_lines - 6));
	free_matrix(map);
	if (check_map_info(data))
		return (1);
	if (create_images(data))
		return (2);
	return (0);
}
