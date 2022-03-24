/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 22:20:21 by elima-me          #+#    #+#             */
/*   Updated: 2021/06/03 14:44:38 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	len_src;

	if (dst == NULL || src == NULL)
		return (0);
	len_src = ft_strlen(src);
	i = 0;
	if (n > 0)
	{
		while ((src[i] != '\0') && (i < (n - 1)))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		return (len_src);
	}
	if (n == 0)
		dst[ft_strlen(dst)] = '\0';
	return (len_src);
}
