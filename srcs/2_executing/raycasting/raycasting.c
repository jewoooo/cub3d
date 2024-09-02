/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:03:11 by jewlee            #+#    #+#             */
/*   Updated: 2024/09/02 14:35:57 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

typedef struct s_var
{
	int		line_h;
	int		draw_st;
	int		draw_en;
	int		color;
}	t_var;

void	ver_line(t_cub3d *info, int x, t_var vars)
{
	int	y;

	y = vars.draw_st;
	while (y < vars.draw_en)
	{
		my_mlx_pixel_put(info->data, x, y, vars.color);
		y++;
	}
}

void	choose_color(t_cub3d *info, t_var *vars)
{
	if (info->map_data.map[info->player->map_y][info->player->map_x] == WALL)
		vars->color = 0xFF0000;
	else
		vars->color = 0x000000;
	if (info->ray->is_side == true)
		vars->color = vars->color / 2;
}

void	cast_rays(t_cub3d *info)
{
	int		x;
	t_var	vars;

	x = -1;
	while (++x < S_WIDTH)
	{
		calc_ray_direction(info, x);
		calc_delta_dist(info);
		calc_step_and_side_dist(info);
		execute_dda(info);
		calc_dist(info);
		vars.line_h = (int)(S_HEIGHT / info->ray->dist);
		vars.draw_st = -vars.line_h / 2 + S_HEIGHT / 2;
		if (vars.draw_st < 0)
			vars.draw_st = 0;
		vars.draw_en = vars.line_h / 2 + S_HEIGHT / 2;
		if (vars.draw_en >= S_HEIGHT)
			vars.draw_en = S_HEIGHT - 1;
		choose_color(info, &vars);
		ver_line(info, x, vars);
	}
}
