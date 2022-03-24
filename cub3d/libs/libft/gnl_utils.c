/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:35:44 by elima-me          #+#    #+#             */
/*   Updated: 2022/03/24 16:02:33 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int	gnl_ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

size_t	gnl_ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	gnl_ft_strcopy(char *dst, char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!src || len == 0)
		return ;
	while (src[i] && i < len - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return ;
}

char	*gnl_ft_strjoin(char *dst, char *src, size_t len)
{
	char	*new;

	if (!dst && !src)
		return (NULL);
	new = (char *)gnl_ft_calloc(sizeof(char), (gnl_ft_strlen(dst) + len + 1));
	if (!new)
		return (NULL);
	gnl_ft_strcopy(new, dst, gnl_ft_strlen(dst) + 1);
	gnl_ft_strcopy((new + gnl_ft_strlen(dst)), src, len + 1);
	if (dst)
		free(dst);
	return (new);
}

char	*gnl_ft_strdup(char *str)
{
	size_t	size_str;
	char	*new_str;

	size_str = gnl_ft_strlen(str);
	new_str = (char *)gnl_ft_calloc(sizeof(char), size_str + 1);
	if (str == NULL || !new_str)
		return (NULL);
	gnl_ft_strcopy(new_str, str, size_str + 1);
	return (new_str);
}
