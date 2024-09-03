/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:55:35 by jewlee            #+#    #+#             */
/*   Updated: 2024/09/03 12:54:19 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	prepare_for_executing(t_cub3d *info)
{
	info->window = mlx_new_window(info->mlx, S_WIDTH, S_HEIGHT, "cub3d");
	if (!info->window)
		ft_err("prepare_for_executing :: failed to create window.");
	init_structs(info);
	setup_player_and_camera(info);
	info->data->img = mlx_new_image(info->mlx, S_WIDTH, S_HEIGHT);
	info->data->addr = mlx_get_data_addr(info->data->img, &info->data->bpp,
			&info->data->line_len, &info->data->endian);
}
