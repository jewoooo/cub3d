/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:03:11 by jewlee            #+#    #+#             */
/*   Updated: 2024/09/02 22:18:31 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

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

void	execute_dda(t_cub3d *info)
{
	info->ray->is_hit = false;
	while (info->ray->is_hit == false)
	{
		if (info->ray->side_dist_x < info->ray->side_dist_y)
		{
			info->ray->side_dist_x += info->ray->delta_dist_x;
			info->player->map_x += info->ray->step_x;
			info->ray->is_side = false;
		}
		else
		{
			info->ray->side_dist_y += info->ray->delta_dist_y;
			info->player->map_y += info->ray->step_y;
			info->ray->is_side = true;
		}
		if (is_out_of_map(info) == true ||
			info->map_data.map[info->player->map_y][info->player->map_x] == WALL)
			info->ray->is_hit = true;
	}
}

void	tex_ver_line(t_cub3d *info, t_var *vars, int x)
{
	int	i;

	i = vars->draw_st;
	while (i < vars->draw_en)
	{
		vars->tex_y = (int)vars->tex_pos & (T_HEIGHT - 1);
		vars->tex_pos += vars->step;
		vars->color = info->map_data.walls[vars->tex_num]\
				[T_HEIGHT * vars->tex_y + vars->tex_x];
		if (info->ray->is_side == 1)
			vars->color = (vars->color >> 1) & 8355711;
		info->buff[i][x] = vars->color;
		info->re_buf = true;
		i++;
	}
}

void	prepare_buff(t_cub3d *info)
{
	int	i;

	i = -1;
	while (++i < S_HEIGHT)
		ft_memset(info->buff[i], 0, sizeof(int) * S_WIDTH);
}

void	cast_rays(t_cub3d *info)
{
	int		x;
	t_var	vars;

	x = -1;
	while (++x < S_WIDTH)
	{
		if (info->re_buf == true)
			prepare_buff(info);
		calc_ray_direction(info, x);
		calc_delta_dist(info);
		calc_step_and_side_dist(info);
		execute_dda(info);
		calc_dist(info);
		calc_vertical_line(info, &vars);
		vars.tex_num = info->map_data.map[info->player->map_y][info->player->map_x];
	
		if (info->ray->is_side == false)
			vars.wall_x = info->player->pos_y + info->ray->dist * info->ray->dir_y;
		else
			vars.wall_x = info->player->pos_x + info->ray->dist * info->ray->dir_x;
		vars.wall_x -= floor(vars.wall_x);
		vars.tex_x = (int)(vars.wall_x * (double)T_WIDTH);
		if (info->ray->is_side == false && info->ray->dir_x > 0)
			vars.tex_x = T_WIDTH - vars.tex_x - 1;
		if (info->ray->is_side == true && info->ray->dir_y < 0)
			vars.tex_x = T_WIDTH - vars.tex_x - 1;
		vars.step = 1.0 * T_HEIGHT / vars.line_h;
		vars.tex_pos = (vars.draw_st - S_HEIGHT / 2 + vars.line_h / 2) * vars.step;
		// choose_color(info, &vars);
		// ver_line(info, x, vars);
		tex_ver_line(info, &vars, x);
	}
}
