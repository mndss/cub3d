#ifndef CUB3D_H

# define CUB3D_H
# define ERROR_SIZE 3

# include <mlx.h>
# include <libft.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

enum {
	ERR_ARGS,
	ERR_INVALID_EXT,
	ERR_NOT_FOUND
};

//UTILS
void	free_matrix(void **ptr);

//CHECKING ERRORS
int	ft_setup(int argc, char *argv[]);
int	invalid_args(int argc, const char *map);

//READ MAP
int		count_lines(char *filename);
char	**read_map(char *filename, int n_lines);

//TEMP
void	print_map(char **map);

#endif