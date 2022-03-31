#ifndef CUB3D_H

# define CUB3D_H
# define ERROR_SIZE 6
# define PI 3.141592

# include <mlx.h>
# include <libft.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef struct s_player {
	int		y;
	int		x;
	float	direction;
} t_player;

typedef struct s_map_info {
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	char		**map;
} t_map_info;

typedef struct s_data {
	void		*mlx;
	void		*win;
	float		fov_angle;
	int			pxl_p_ray;
	t_map_info	map;
	t_player	player;
} t_data;

enum {
	ERR_ARGS,
	ERR_INVALID_EXT,
	ERR_NOT_FOUND,
	ERR_DOUBLE_PLAYER,
	ERR_NO_PLAYER,
	ERR_INVALID_MAP
};

//UTILS
void	free_matrix(char **ptr);
int		print_err(int msg);

//CHECKING ERRORS
int	ft_setup(int argc, char *argv[], t_data *data);
int	invalid_args(int argc, const char *map);
int	check_map(t_data *data);

//READ MAP
int		count_lines(char *filename);
char	**read_map(char *filename, int n_lines);
char	*get_textures(char *prefix, char **map);
void	get_info(char **map, t_map_info *map_info, int map_size);
int		get_map(char **map, t_map_info *map_info, int map_size);

//TEMP
void	print_map(char **map);
void	print_struct_map(t_map_info *map_info);
void	print_player_info(t_player *player);

//CREATE MAP 
int		create_images(t_map_info *map_info);


// GAME CONFIG
int	game_config(t_data *data);
#endif