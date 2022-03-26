/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:06:40 by elima-me          #+#    #+#             */
/*   Updated: 2021/06/04 19:02:17 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_words(const char *s, char c)
{
	int	words;
	int	validator;
	int	i;

	words = 0;
	validator = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && validator)
		{			
			validator = 0;
			words++;
		}
		else if (s[i++] == c)
			validator = 1;
	}
	return (words);
}

static size_t	size_words(const char *s, char c)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static void	freeall(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static char	**fill_array(char const *s, char c, char **words, char **words2)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		if (s[i] != c)
		{
			*words = ft_substr(&s[i], 0, size_words(&s[i], c));
			if (!words)
			{
				freeall(words);
				return (NULL);
			}
			i = i + size_words(&s[i], c);
			words++;
		}
	}
	*words = NULL;
	return (words2);
}

char	**ft_split(char const *s, char c)
{
	int		count_words;
	char	**words;

	if (s == NULL)
		return (NULL);
	count_words = check_words(s, c);
	words = (char **)ft_calloc(sizeof(char *), (count_words + 1));
	if (!words)
		return (NULL);
	words = fill_array(s, c, words, words);
	if (words == NULL)
		return (NULL);
	return (words);
}
