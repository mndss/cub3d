/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:47:47 by guferrei          #+#    #+#             */
/*   Updated: 2022/04/11 15:46:51 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H
# define ERROR_SIZE 7
# define PI 3.141592
# define PXL_P_RAY 1
# define WIN_WIDHT 800
# define WIN_HEIGHT 600
# define TILE_SIZE 32
# define MAX_INT 2147483647
# define RIGHT_ARROW 65361
# define LEFT_ARROW 65363

# include <mlx.h>
# include <libft.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>

typedef struct	s_img_addr {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_addr;


typedef struct s_cord {
	float	x;
	float	y;
}	t_cord;

typedef struct s_dist {
	float	x;
	float	y;
	float	dist;
}	t_dist;

typedef struct s_player {
	int		y;
	int		x;
	int		turn_direction;
	int		walk_direction;
	int		move_speed;
	int		rotation_speed;
	float	direction;
}	t_player;

typedef struct s_hits {
	t_cord	intercept;
	t_cord	step;
	t_cord	next_hit;
}	t_hits;

typedef struct s_rays
{
	float		ray_angle;
	float		wall_hit_x;
	float		wall_hit_y;
	float		distance;
	float		wall_height;
	bool		hit_vert;
	bool		is_down;
	bool		is_up;
	bool		is_right;
	bool		is_left;
}	t_rays;

typedef struct s_map_info {
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	int			color_f;
	int			color_c;
	char		**map;
}	t_map_info;

typedef struct s_data {
	void		*mlx;
	void		*win;
	int			tile_size;
	float		fov_angle;
	t_map_info	map;
	t_player	player;
	t_rays		rays[WIN_WIDHT];
	t_img_addr	img_addr;
}	t_data;

enum {
	ERR_ARGS,
	ERR_INVALID_EXT,
	ERR_NOT_FOUND,
	ERR_DOUBLE_PLAYER,
	ERR_NO_PLAYER,
	ERR_INVALID_MAP,
	ERR_INVALID_COLOR
};

//UTILS
void	free_matrix(char **ptr);
int		print_err(int msg);
int		set_colors(char *str_color);
void	ft_clean(t_map_info *map);

//CHECKING ERRORS
int		ft_setup(int argc, char *argv[], t_data *data);
int		check_map(t_data *data);

//READ MAP
int		count_lines(char *filename);
char	**read_map(char *filename, int n_lines);
char	*get_colors(char *prefix, char **map);
void	get_info(char **map, t_map_info *map_info, int map_size);
int		get_map(char **map, t_map_info *map_info, int map_size);

//CASTING RAYS
void	create_rays(t_data *data);
void	init_ray(t_rays *ray);
bool	is_wall(t_cord *hit, bool up, bool left, char **map);
float	find_distance(int px, int py, int wx, int wy);

//TEMP
void	print_map(char **map);
void	print_struct_map(t_map_info *map_info);
void	print_player_info(t_player *player);

//CREATE MAP
int		create_images(t_map_info *map_info);

// GAME CONFIG
int		game_config(t_data *data);

//FIND INTERCEPTIONS
void	vert_hit(t_dist *vert, t_rays *ray, t_player *player, char **map);
void	horz_hit(t_dist *horz, t_rays *ray, t_player *player, char **map);

//RENDER WALLS
int		render_walls(t_data *data);

//MOVEMENTS
int	key_press(int keycode, t_data *data);
int	key_release(int keycode, t_data *data);

#endif