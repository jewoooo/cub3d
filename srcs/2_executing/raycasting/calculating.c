/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculating.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:35:33 by jewlee            #+#    #+#             */
/*   Updated: 2024/09/02 14:36:29 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	calc_ray_direction(t_cub3d *info, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)S_WIDTH - 1;
	info->ray->dir_x = info->player->dir_x + info->cam->plane_x * camera_x;
	info->ray->dir_y = info->player->dir_y + info->cam->plane_y * camera_x;
}

void	calc_delta_dist(t_cub3d *info)
{
	info->ray->delta_dist_x = fabs(1 / info->ray->dir_x);
	info->ray->delta_dist_y = fabs(1 / info->ray->dir_y);
}

void	calc_step_and_side_dist(t_cub3d *info)
{
	info->player->map_x = (int)info->player->pos_x;
	info->player->map_y = (int)info->player->pos_y;
	if (info->ray->dir_x < 0)
	{
		info->ray->step_x = -1;
		info->ray->side_dist_x = (info->player->pos_x - info->player->map_x) * info->ray->delta_dist_x;
	}
	else
	{
		info->ray->step_x = 1;
		info->ray->side_dist_x = (info->player->map_x + 1.0 - info->player->pos_x) * info->ray->delta_dist_x;
	}
	if (info->ray->dir_y < 0)
	{
		info->ray->step_y = -1;
		info->ray->side_dist_y = (info->player->pos_y - info->player->map_y) * info->ray->delta_dist_y;
	}
	else
	{
		info->ray->step_y = 1;
		info->ray->side_dist_y = (info->player->map_y + 1.0 - info->player->pos_y) * info->ray->delta_dist_y;
	}
}

void	calc_dist(t_cub3d *info)
{
	if (info->ray->is_side == false)
		info->ray->dist = (info->player->map_x - info->player->pos_x + (1 - info->ray->step_x) / 2) / info->ray->dir_x;
	else
		info->ray->dist = (info->player->map_y - info->player->pos_y + (1 - info->ray->step_y) / 2) / info->ray->dir_y;
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
