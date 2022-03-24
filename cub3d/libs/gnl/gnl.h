#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/resource.h>
# include <limits.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>

int		ft_strchr(char *s, char c);
size_t	ft_strlen(char *s);
void	ft_strcopy(char *dst, char *src, size_t len);
char	*ft_strjoin(char *dst, char *src, size_t len);
int		get_next_line(int fd, char **line);
char	*ft_strdup(char *str);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
