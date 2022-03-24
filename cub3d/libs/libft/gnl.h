/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:35:44 by elima-me          #+#    #+#             */
/*   Updated: 2022/03/24 15:56:14 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/resource.h>
# include <limits.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>

int		gnl_ft_strchr(char *s, char c);
size_t	gnl_ft_strlen(char *s);
void	gnl_ft_strcopy(char *dst, char *src, size_t len);
char	*gnl_ft_strjoin(char *dst, char *src, size_t len);
int		gnl_get_next_line(int fd, char **line);
char	*gnl_ft_strdup(char *str);
void	*gnl_ft_calloc(size_t nmemb, size_t size);

#endif
