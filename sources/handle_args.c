/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:26:33 by guferrei          #+#    #+#             */
/*   Updated: 2022/03/31 17:43:46 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	invalid_args(int argc, const char *map)
{
	if (argc != 2)
		return (print_err(ERR_ARGS));
	if (ft_strncmp(&map[strlen(map) - 4], ".cub", ft_strlen(map)))
		return (print_err(ERR_INVALID_EXT));
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
	map = read_map(argv[1], n_lines);
	get_info(map, &data->map, (n_lines - 6));
	free_matrix(map);
	check_map(data);
	//if (create_images(map_info))
	//	return (2);
	return (0);
}
