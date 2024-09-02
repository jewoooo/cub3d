/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:54:49 by jewlee            #+#    #+#             */
/*   Updated: 2024/09/02 14:28:21 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	setup_camera(t_cub3d *info, t_tile_type type)
{
	if (type == ST_N)
	{
		info->cam->plane_x = 0.66;
		info->cam->plane_y = 0;
	}
	else if (type == ST_S)
	{
		info->cam->plane_x = -0.66;
		info->cam->plane_y = 0;
	}
	else if (type == ST_E)
	{
		info->cam->plane_x = 0;
		info->cam->plane_y = 0.66;
	}
	else if (type == ST_W)
	{
		info->cam->plane_x = 0;
		info->cam->plane_y = -0.66;
	}
}

static void	setup_player(t_cub3d *info, t_tile_type type)
{
	if (type == ST_N)
	{
		info->player->dir_x = 0;
		info->player->dir_y = -1;
	}
	else if (type == ST_S)
	{
		info->player->dir_x = 0;
		info->player->dir_y = 1;
	}
	else if (type == ST_E)
	{
		info->player->dir_x = 1;
		info->player->dir_y = 0;
	}
	else if (type == ST_W)
	{
		info->player->dir_x = -1;
		info->player->dir_y = 0;
	}
}

void	setup_player_and_camera(t_cub3d *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->map_data.height)
	{
		j = -1;
		while (++j < info->map_data.width)
		{
			if (info->map_data.map[i][j] == ST_N
				|| info->map_data.map[i][j] == ST_S
				|| info->map_data.map[i][j] == ST_W
				|| info->map_data.map[i][j] == ST_E)
			{
				info->player->pos_x = j;
				info->player->pos_y = i;
				setup_player(info, info->map_data.map[i][j]);
				setup_camera(info, info->map_data.map[i][j]);
			}
		}
	}
}
