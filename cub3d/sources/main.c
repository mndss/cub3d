/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:57:10 by elima-me          #+#    #+#             */
/*   Updated: 2022/03/21 14:24:41 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_setup(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Invalid numbers of arguments\n");
		return (1);
	}
	if (ft_strncmp(&argv[1][strlen(argv[1]) - 4], ".cub", ft_strlen(argv[1])))
	{
		printf("Invalid extension from map\n");
		return (2);
	}
	return (0);
}

int main(int argc, char *argv[])
{
	ft_setup(argc, argv);
	return (0);
}
