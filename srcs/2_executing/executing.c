/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:45:14 by jewlee            #+#    #+#             */
/*   Updated: 2024/09/03 16:02:07 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_buff_to_img(t_cub3d *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < S_HEIGHT)
	{
		j = -1;
		while (++j < S_WIDTH)
			((int *)info->data->addr)[i * S_WIDTH + j] = info->buff[i][j];
	}
	ft_memset(info->buff, 0, sizeof(info->buff));
}

int render_frame(t_cub3d *info)
{
	if (!info->re_buf)
		return (0);
	//mlx_clear_window(info->mlx, info->window);
	cast_rays(info);
	put_buff_to_img(info);
	mlx_put_image_to_window(info->mlx, info->window, info->data->img, 0, 0);
	info->re_buf = false;
	return (0);
}

void	execute(t_cub3d *info)
{
	prepare_for_executing(info);
	info->re_buf = true;
	mlx_loop_hook(info->mlx, &render_frame, info);
	mlx_hook(info->window, X_EVENT_KEY_PRESS, 0, &key_press, info);
	mlx_loop(info->mlx);
}
