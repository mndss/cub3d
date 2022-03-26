/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 23:56:44 by elima-me          #+#    #+#             */
/*   Updated: 2021/06/02 21:16:01 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	count;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_len;
	count = 0;
	if (dst_len >= size)
		return (src_len + size);
	while (src[count] != '\0' && i < (size - 1))
	{
		dst[i] = src[count];
		count++;
		i++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}
