#include "gnl.h"

int	ft_strchr(char *s, char c)
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

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	ft_strcopy(char *dst, char *src, size_t len)
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

char	*ft_strjoin(char *dst, char *src, size_t len)
{
	char	*new;

	if (!dst && !src)
		return (NULL);
	new = (char *)ft_calloc(sizeof(char), (ft_strlen(dst) + len + 1));
	if (!new)
		return (NULL);
	ft_strcopy(new, dst, ft_strlen(dst) + 1);
	ft_strcopy((new + ft_strlen(dst)), src, len + 1);
	if (dst)
		free(dst);
	return (new);
}

char	*ft_strdup(char *str)
{
	size_t	size_str;
	char	*new_str;

	size_str = ft_strlen(str);
	new_str = (char *)ft_calloc(sizeof(char), size_str + 1);
	if (str == NULL || !new_str)
		return (NULL);
	ft_strcopy(new_str, str, size_str + 1);
	return (new_str);
}
