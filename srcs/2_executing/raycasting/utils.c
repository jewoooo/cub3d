/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:36:14 by jewlee            #+#    #+#             */
/*   Updated: 2024/09/02 14:36:32 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

bool	is_out_of_map(t_cub3d *info)
{
	t_player	*player;

	player = info->player;
	if (player->map_x < 0 ||
		player->map_x >= info->map_data.width||
			player->map_y < 0 ||
			player->map_y >= info->map_data.height)
		return (true);
	if (info->map_data.map[info->player->map_y][info->player->map_x] == EMPTY)
		return (true);
	return (false);	
}
