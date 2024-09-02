/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:45:14 by jewlee            #+#    #+#             */
/*   Updated: 2024/09/02 14:39:20 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int render_frame(t_cub3d *info)
{
	prepare_image(info);
	cast_rays(info);
	mlx_put_image_to_window(info->mlx, info->window, info->data->img, 0, 0);
	return (0);
}

void	execute(t_cub3d *info)
{
	prepare_for_executing(info);
	mlx_loop_hook(info->mlx, &render_frame, info);
	mlx_hook(info->window, X_EVENT_KEY_PRESS, 0, &key_press, info);
	mlx_loop(info->mlx);
}
