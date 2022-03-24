/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:40:29 by elima-me          #+#    #+#             */
/*   Updated: 2021/06/01 18:17:04 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	while (*s1 && ft_strrchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strrchr(set, s1[len]))
		len--;
	return (ft_substr(s1, 0, len + 1));
}
