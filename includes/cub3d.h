#ifndef CUB3D_H

# define CUB3D_H
# define ERROR_SIZE 3

# include <mlx.h>
# include <libft.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef struct s_map_info {
	char *no;
	char *so;
	char *we;
	char *ea;
	char *f;
	char *c;
	char **map;
} t_map_info;


enum {
	ERR_ARGS,
	ERR_INVALID_EXT,
	ERR_NOT_FOUND
};

//UTILS
void	free_matrix(void **ptr);
int	print_err(int msg);

//CHECKING ERRORS
int	ft_setup(int argc, char *argv[], t_map_info *map_info);
int	invalid_args(int argc, const char *map);

//READ MAP
int		count_lines(char *filename);
char	**read_map(char *filename, int n_lines);
char	*get_textures(char *prefix, char **map);
void	get_info(char **map, t_map_info *map_info, int map_size);
int		get_map(char **map, t_map_info *map_info, int map_size);

//TEMP
void	print_map(char **map);
void	print_struct(t_map_info *map_info);


//CREATE MAP 
int		create_images(t_map_info *map_info);

#endif