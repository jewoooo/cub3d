/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:50:50 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/27 15:44:02 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <sys/fcntl.h>

# include "../mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"
# include "../lib/ft_printf/ft_printf.h"

# define NONE -1

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
	START
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

typedef struct s_cub3d
{
	void		*mlx;
	void		*window;
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

#endif