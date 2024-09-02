/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:57:00 by jewlee            #+#    #+#             */
/*   Updated: 2024/09/02 14:13:56 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_structs(t_cub3d *info)
{
	info->cam = ft_calloc(1, sizeof(t_camera));
	if (!info->cam)
		ft_err("init_structs :: failed malloc (*cam).");
	info->ray = ft_calloc(1, sizeof(t_ray));
	if (!info->ray)
		ft_err("init_structs :: failed malloc (*ray).");
	info->player = ft_calloc(1, sizeof(t_player));
	if (!info->player)
		ft_err("init_structs :: failed malloc (*player).");
	info->data = ft_calloc(1, sizeof(t_img));
	if (!info->data)
		ft_err("init_structs :: failed malloc (*data).");
}
