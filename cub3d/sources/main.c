/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:57:10 by elima-me          #+#    #+#             */
/*   Updated: 2022/03/24 16:39:38 by guferrei         ###   ########.fr       */
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

int	invalid_args(int argc, char *argv[])
{
	if (argc != 2)
		return (print_err(ERR_ARGS));
	if (ft_strncmp(&argv[1][strlen(argv[1]) - 4], ".cub", ft_strlen(argv[1])))
		return (print_err(ERR_INVALID_EXT));
	return (0);
}

int	ft_setup(int argc, char *argv[])
{
	if (invalid_args(argc, argv))
		return (1);
	return (0);
}

int main(int argc, char *argv[])
{
	ft_setup(argc, argv);
	return (0);
}
