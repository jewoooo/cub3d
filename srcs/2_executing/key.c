/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:59:01 by jewlee            #+#    #+#             */
/*   Updated: 2024/09/02 15:38:10 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// 어디로 빼야할지?
bool	is_available_tile(int x, int y, t_tile_type **map)
{
	if (map[y][x] == GROUND || map[y][x] == ST_N ||
		map[y][x] == ST_S || map[y][x] == ST_W || map[y][x] == ST_E)
		return (true);
	return (false);
}

static void	move_forward_backward(t_cub3d *info, int key)
{
	t_player	*player;
	t_tile_type	**map;

	player = info->player;
	map = info->map_data.map;
	if (key == K_W)
	{
		if (is_available_tile((int)(player->pos_x + player->dir_x * MOVE_SPD), (int)player->pos_y, map))
			player->pos_x += player->dir_x * MOVE_SPD;
		if (is_available_tile((int)player->pos_x, (int)(player->pos_y + player->dir_y * MOVE_SPD), map))
			player->pos_y += player->dir_y * MOVE_SPD;
	}
	if (key == K_S)
	{
		if (is_available_tile((int)(player->pos_x - player->dir_x * MOVE_SPD), (int)player->pos_y, map))
			player->pos_x -= player->dir_x * MOVE_SPD;
		if (is_available_tile((int)player->pos_x, (int)(player->pos_y - player->dir_y * MOVE_SPD), map))
			player->pos_y -= player->dir_y * MOVE_SPD;
	}
}

static void	move_left_right(t_cub3d *info, int key)
{
	t_player	*player;
	t_tile_type	**map;

	player = info->player;
	map = info->map_data.map;
	if (key == K_A)
	{
		if (is_available_tile((int)(player->pos_x + player->dir_y * MOVE_SPD), (int)player->pos_y, map))
			player->pos_x += player->dir_y * MOVE_SPD;
		if (is_available_tile((int)player->pos_x, (int)(player->pos_y - player->dir_x * MOVE_SPD), map))
			player->pos_y -= player->dir_x * MOVE_SPD;
	}
	if (key == K_D)
	{
		if (is_available_tile((int)(player->pos_x - player->dir_y * MOVE_SPD), (int)player->pos_y, map))
			player->pos_x -= player->dir_y * MOVE_SPD;
		if (is_available_tile((int)player->pos_x, (int)(player->pos_y + player->dir_x * MOVE_SPD), map))
			player->pos_y += player->dir_x * MOVE_SPD;
	}
}

static void	rotate_left_right(t_cub3d *info, int key)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->player->dir_x;
	old_plane_x = info->cam->plane_x;
	if (key == K_LEFT)
	{
		info->player->dir_x = info->player->dir_x * cos(-ROT_SPD) - info->player->dir_y * sin(-ROT_SPD);
		info->player->dir_y = old_dir_x * sin(-ROT_SPD) + info->player->dir_y * cos(-ROT_SPD);
		info->cam->plane_x = info->cam->plane_x * cos(-ROT_SPD) - info->cam->plane_y * sin(-ROT_SPD);
		info->cam->plane_y = old_plane_x * sin(-ROT_SPD) + info->cam->plane_y * cos(-ROT_SPD);
	}
	if (key == K_RIGHT)
	{
		info->player->dir_x = info->player->dir_x * cos(ROT_SPD) - info->player->dir_y * sin(ROT_SPD);
		info->player->dir_y = old_dir_x * sin(ROT_SPD) + info->player->dir_y * cos(ROT_SPD);
		info->cam->plane_x = info->cam->plane_x * cos(ROT_SPD) - info->cam->plane_y * sin(ROT_SPD);
		info->cam->plane_y = old_plane_x * sin(ROT_SPD) + info->cam->plane_y * cos(ROT_SPD);
	}
}

// 게걸음 + 방향표 눌렀을때 화면 돌리기 구현해야함.
int	key_press(int key, t_cub3d *info)
{
	if (key == K_ESC)
		exit(0);
	if (key == K_W || key == K_S)
		move_forward_backward(info, key);
	if (key == K_A || key == K_D)
		move_left_right(info, key);
	if (key == K_LEFT || key == K_RIGHT)
		rotate_left_right(info, key);
	return (0);
}
