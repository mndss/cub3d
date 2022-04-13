/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:50:05 by elima-me          #+#    #+#             */
/*   Updated: 2022/04/13 16:55:23 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	char_occurrence(char *str, char c)
{
	int	count;
	int	times;

	count = 0;
	times = 0;
	while (str[count])
	{
		if (str[count] == c)
			times++;
		count++;
	}
	return (times);
}

int	check_empty_line(char *str)
{
	int	c;

	c = 0;
	while (str[c])
	{
		if (str[c] != ' ')
			return (0);
		c++;
	}
	return (1);
}
