/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:08:03 by elima-me          #+#    #+#             */
/*   Updated: 2021/05/31 14:12:08 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	find;
	size_t	i;

	str = (char *)s;
	find = c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == find)
			return (str + i);
		i--;
	}
	if (s[i] == find)
		return (str + i);
	return (NULL);
}
