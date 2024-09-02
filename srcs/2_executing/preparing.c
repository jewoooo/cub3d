/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:55:35 by jewlee            #+#    #+#             */
/*   Updated: 2024/09/02 14:35:22 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	prepare_image(t_cub3d *info)
{
	if (info->data->img != NULL)
		mlx_destroy_image(info->mlx, info->data->img);
	info->data->img = mlx_new_image(info->mlx, S_WIDTH, S_HEIGHT);
	info->data->addr = mlx_get_data_addr(info->data->img, &info->data->bpp,
			&info->data->line_len, &info->data->endian);
}

void	prepare_for_executing(t_cub3d *info)
{
	info->window = mlx_new_window(info->mlx, S_WIDTH, S_HEIGHT, "cub3d");
	init_structs(info);
	setup_player_and_camera(info);
}
