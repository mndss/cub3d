/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:47:47 by guferrei          #+#    #+#             */
/*   Updated: 2022/04/06 18:31:42 by elima-me         ###   ########.fr       */
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

# include <mlx.h>
# include <libft.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>

typedef struct s_cord {
	int	x;
	int	y;
}	t_cord;

typedef struct s_dist {
	int	x;
	int	y;
	int	dist;
}	t_dist;

typedef struct s_player {
	int		y;
	int		x;
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
	int			wall_hit_x;
	int			wall_hit_y;
	int			distance;
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

//CHECKING ERRORS
int		ft_setup(int argc, char *argv[], t_data *data);
int		invalid_args(int argc, const char *map);
int		check_map(t_data *data);

//READ MAP
int		count_lines(char *filename);
char	**read_map(char *filename, int n_lines);
char	*get_textures(char *prefix, char **map);
void	get_info(char **map, t_map_info *map_info, int map_size);
int		get_map(char **map, t_map_info *map_info, int map_size);

//CASTING RAYS
float	normalize_angle(float angle);
void	init_ray(t_rays *ray);
bool	is_wall(t_cord *hit, bool up, bool left, char **map);
int		find_distance(int px, int py, int wx, int wy);
int		cast_ray(t_rays *ray, t_player *player, char **map);

//TEMP
void	print_map(char **map);
void	print_struct_map(t_map_info *map_info);
void	print_player_info(t_player *player);

//CREATE MAP
int		create_images(t_map_info *map_info);

// GAME CONFIG
int		game_config(t_data *data);

//FIND VERT INTERCEPTIONS
void	vert_hit(t_dist *vert, t_rays *ray, t_player *player, char **map);
void	find_intercept_vert(t_cord *intercept, t_rays *ray, t_player *player);
void	find_step_vert(t_cord *step, t_rays *ray);
void	horz_hit(t_dist *horz, t_rays *ray, t_player *player, char **map);
#endif