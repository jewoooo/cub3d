/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:03:11 by jewlee            #+#    #+#             */
/*   Updated: 2024/09/03 16:20:49 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

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
			info->ray->is_side = true;// 수직면
		}
		else
		{
			info->ray->side_dist_y += info->ray->delta_dist_y;
			info->player->map_y += info->ray->step_y;
			info->ray->is_side = false;// 수평면 충돌
		}
		if (is_out_of_map(info) == true ||
			info->map_data.map[info->player->map_y][info->player->map_x] == WALL)
			info->ray->is_hit = true;
	}
}

void	tex_ver_line(t_cub3d *info, t_var *vars, int x)
{
	int	color;
	int	i;

	i = vars->draw_st;
	// 레이캐스팅 결과 값을 가지고, x 좌표는 고정한 채로 y 길이만큼 픽셀을 박는다.
	while (i < vars->draw_en)
	{
		vars->tex_y = (int)vars->tex_pos & (T_HEIGHT - 1);
		vars->tex_pos += vars->step;
		// 미리 준비해둔 wall 텍스쳐에서 대응되는 픽셀을 뜯어온다.
		color = info->map_data.walls[vars->tex_num][T_HEIGHT * vars->tex_y + vars->tex_x];
		// if (info->ray->is_side == 1)
			// color = (vars->color >> 1) & 8355711;
		info->buff[i][x] = color;
		i++;
	}
}
/*
북쪽 벽을 보여줘야할 때
if (info->ray->is_side == false)
{
	dir_y > 0
}

남쪽 벽을 보여줘야할때
if (info->ray->is_side == false)
{
	dir_y < 0
}

동쪽 벽을 보여줘야할 때
if (info->ray->is_side == true)
{
	dir_x < 0
}

서쪽 벽을 보여줘야할 때
if (info->ray->is_side == true)
{
	dir_x > 0
}
*/
int		check_compass(t_cub3d *info)
{
	if (info->ray->is_side == false && info->ray->dir_y < 0)// 수평 면 충돌 + ray의 방향 북쪽
		return (NO);
	if (info->ray->is_side == false && info->ray->dir_y > 0)// 수평 면 충돌 + ray의 방향 남쪽
		return (SO);
	if (info->ray->is_side == true && info->ray->dir_x < 0)// 수직 면 충돌 + ray의 방향 서쪽
		return (EA);
	if (info->ray->is_side == true && info->ray->dir_x > 0)// 수직 면 충돌 + ray 방향 동쪽
		return (WE);
	return (NO);
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
		calc_vertical_line(info, &vars);
		// vars.tex_num = 0;
		vars.tex_num = check_compass(info);
		if (info->ray->is_side == false)// 수평면에 부딪힌 경우 x 좌표
			vars.wall_x = info->player->pos_y + info->ray->dist * info->ray->dir_y;
		else// 수직선에 부딪힌 경우 y 좌표
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
