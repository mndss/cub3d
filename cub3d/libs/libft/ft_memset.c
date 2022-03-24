/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:20:27 by eduardo           #+#    #+#             */
/*   Updated: 2021/08/12 17:21:13 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char		*str;
	unsigned char		cc;
	size_t				i;

	str = s;
	cc = c;
	i = 0;
	while (i < n)
	{
		str[i] = cc;
		i++;
	}
	return (s);
}
