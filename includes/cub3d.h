/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:50:50 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/02 14:52:11 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <sys/fcntl.h>
# include <stdbool.h>
# include <math.h>
# include <stdio.h>// for log

# include "../mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"
# include "../lib/ft_printf/ft_printf.h"

# define NONE -1
# define MOVE_SPD 0.5
# define ROT_SPD 0.3
# define S_WIDTH 640
# define S_HEIGHT 480

/* key constants */
# define X_EVENT_KEY_PRESS	2
# define K_ESC				53
# define K_W				13
# define K_A				0
# define K_S				1
# define K_D				2
# define K_LEFT				123
# define K_RIGHT			124

typedef enum e_bool
{
	FAIL = -1,
	FALSE,
	TRUE
}	t_bool;

typedef enum e_tile_type
{
	EMPTY = -1,
	GROUND,
	WALL,
	ST_N,
	ST_S,
	ST_W,
	ST_E
}	t_tile_type;

typedef enum wall_type
{
	NO = 0,
	SO,
	WE,
	EA
}	t_wall_type;

typedef	struct s_map_data
{
	t_tile_type	**map; // 2차원 배열
	int			start;
	int			width;
	int			height;
	int			floor[3];
	int			ceil[3];
	void		*walls[4]; // NO SO WE EA
}	t_map_data;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_camera
{
	double	plane_x;
	double	plane_y;
}	t_camera;

typedef struct	s_ray
{
	double	dir_x;
	double	dir_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	dist;
	bool	is_hit;
	bool	is_side;
}	t_ray;

typedef struct	s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;	
}	t_player;

typedef struct s_cub3d
{
	void		*mlx;
	void		*window;
	t_img		*data;
	t_camera	*cam;
	t_ray		*ray;
	t_player	*player;
	t_map_data	map_data;
}	t_cub3d;

/* 0_exit */
void	ft_err(char *err);
void	ft_err_map(char *err, int row, int col);

/* 1_parsing */
void	parsing(t_cub3d *info, char *file);
/* utils */
int		quick_open_file(char *file, int line);
char	*remove_space(char *src);
void	test_map_array(t_map_data *map_data, t_tile_type **map);
/* load */
void	*load_xpm(t_cub3d *info, char *path, int size);
/* valid */
void	is_valid_file_name(char *file);
void	is_valid_map(t_map_data *map_data, t_tile_type **map);
/* map */
void	convert_to_map(t_cub3d *info, t_map_data *map_data, char *file);

/* 2_executing */
/* executing */
void	execute(t_cub3d *info);
/* setup */
void	setup_player_and_camera(t_cub3d *info);
/* init */
void	init_structs(t_cub3d *info);
/* preparing */
void	prepare_for_executing(t_cub3d *info);
void	prepare_image(t_cub3d *info);
/* key */
int		key_press(int key, t_cub3d *info);

/* 2_executing/raycasting */
void	cast_rays(t_cub3d *info);
/* calculating */
void	calc_ray_direction(t_cub3d *info, int x);
void	calc_delta_dist(t_cub3d *info);
void	calc_step_and_side_dist(t_cub3d *info);
void	calc_dist(t_cub3d *info);
void	execute_dda(t_cub3d *info);
/* utils */
bool	is_out_of_map(t_cub3d *info);

/* utils/mlx */
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
#endif