/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:26:33 by guferrei          #+#    #+#             */
/*   Updated: 2022/03/28 21:05:04 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	print_err(int msg)
{
	char	*err[ERROR_SIZE];

	err[ERR_ARGS] = "Error\nInvalid numbers of arguments\n";
	err[ERR_INVALID_EXT] = "Error\nInvalid extension from map\n";
	err[ERR_NOT_FOUND] = "Error\nFile not found\n";
	ft_putstr_fd(err[msg], 2);
	return (msg + 1);
}

int	invalid_args(int argc, const char *map)
{
	if (argc != 2)
		return (print_err(ERR_ARGS));
	if (ft_strncmp(&map[strlen(map) - 4], ".cub", ft_strlen(map)))
		return (print_err(ERR_INVALID_EXT));
	return (0);
}

int	ft_setup(int argc, char *argv[], t_map_info *map_info)
{
	int		n_lines;
	char	**map;

	if (invalid_args(argc, argv[1]))
		return (1);
	n_lines = count_lines(argv[1]);
	if (n_lines < 0)
		return (print_err(ERR_NOT_FOUND));
	map = read_map(argv[1], n_lines);
	get_info(map, map_info, (n_lines - 6));
	if (create_images(map_info))
		return (2);
	return (0);
}
