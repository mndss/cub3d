/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:47:47 by guferrei          #+#    #+#             */
/*   Updated: 2022/04/12 21:43:33 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H
# define ERROR_SIZE 8
# define PI 3.141592
# define PXL_P_RAY 1
# define WIN_WIDHT 1280
# define WIN_HEIGHT 720
# define TILE_SIZE 2048
# define MAX_INT 2147483647
# define RIGHT_ARROW 65361
# define LEFT_ARROW 65363
# define KEY_W 44
# define KEY_S 101
# define ESC 65307

# include <mlx.h>
# include <libft.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>

typedef struct s_img_addr {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			x;
	int			y;
	__uint32_t	*buffer;
}				t_img_addr;

typedef struct s_img
{
	t_img_addr	no;
	t_img_addr	so;
	t_img_addr	we;
	t_img_addr	ea;
}				t_img;

typedef struct s_proj
{
	float		dist_persp;
	float		wall_height_proj;
	int			wall_strip_height;
	int			wall_top_pxl;
	int			wall_bot_pxl;
	int			dst_from_top;
	int			offset_y;
	int			offset_x;
	__uint32_t	color;
}				t_proj;

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
	float	y;
	float	x;
	int		turn_direction;
	int		walk_direction;
	int		move_speed;
	int		rotation_speed;
	float	direction;
	bool	is_facing_up;
	bool	is_facing_left;
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
	int			n_lines;
	int			n_cols;
}	t_map_info;

typedef struct s_data {
	void		*mlx;
	void		*win;
	int			tile_size;
	float		fov_angle;
	t_img		textures;
	t_map_info	map;
	t_player	player;
	t_rays		rays[WIN_WIDHT];
	t_img_addr	main_img;
}	t_data;

enum {
	ERR_ARGS,
	ERR_INVALID_EXT,
	ERR_NOT_FOUND,
	ERR_DOUBLE_PLAYER,
	ERR_NO_PLAYER,
	ERR_INVALID_MAP,
	ERR_INVALID_COLOR,
	ERR_INVALID_TEXTURE
};

//UTILS
void			free_matrix(char **ptr);
int				print_err(int msg);
int				set_colors(char *str_color);
void			ft_clean(t_map_info *map, t_data *data);
unsigned int	get_color_pxl(t_img_addr *img, int x, int y);
float			normalize_angle(float angle);
void			find_facing_direction(t_player *player);

//CHECKING ERRORS
int				ft_setup(int argc, char *argv[], t_data *data);
int				check_map(t_data *data);

//READ MAP
int				count_lines(char *filename);
char			**read_map(char *filename, int n_lines);
char			*get_colors(char *prefix, char **map);
void			get_info(char **map, t_map_info *map_info, int map_size);
int				get_map(char **map, t_map_info *map_info, int map_size);

//CASTING RAYS
void			create_rays(t_data *data);
void			init_ray(t_rays *ray);
bool			is_wall(t_cord *hit, bool up, bool left, char **map);
float			find_distance(int px, int py, int wx, int wy);

//TEMP
void			print_map(char **map);
void			print_struct_map(t_map_info *map_info);
void			print_player_info(t_player *player);

//CREATE MAP
int				create_images(t_data *data);

// GAME CONFIG
int				game_config(t_data *data);

//FIND INTERCEPTIONS
void			vert_hit(t_dist *vert, t_rays *ray, t_data *data);
void			horz_hit(t_dist *horz, t_rays *ray, t_data *data);

//RENDER WALLS
int				render_walls(t_data *data);
void			render_textures(t_data *data);
void			my_pixel_put(t_img_addr *img_addr, int x, int y, int color);
void			drawn_ceiling(t_img_addr *main_img,
					t_map_info *map, t_proj *proj, int x);
void			drawn_floor(t_img_addr *main_img,
					t_map_info *map, t_proj *proj, int x);
void			draw_walls(t_proj *proj, t_data *data, int x, int y);
__uint32_t		get_hited_texture(t_rays *ray,
					t_proj *proj, t_img *textures);

//MOVEMENTS
int				key_press(int keycode, t_data *data);
int				key_release(int keycode, t_data *data);

//CLOSE GAME 
int				close_game(t_data *data);

#endif