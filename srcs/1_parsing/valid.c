/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:07:58 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/27 16:06:27 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_bool	is_around_empty(t_tile_type **map, int i, int j)
{
	if (map[i - 1][j] == EMPTY || map[i + 1][j] == EMPTY
		|| map[i][j - 1] == EMPTY || map[i][j + 1] == EMPTY)
		return (TRUE);
	return (FALSE);
}

void	is_valid_map(t_map_data *map_data, t_tile_type **map)
{
	int	i;
	int	j;
	
	i = 1;
	while (i < map_data->height)
	{
		j = 1;
		while (j < map_data->width)
		{
			if (is_around_empty(map, i, j))
			{
				if (!(map[i][j] == EMPTY || map[i][j] == WALL))
					ft_err_map("parsing :: boundaries are not wall", i, j);
			}
			j++;
		}
		i++;
	}
	ft_printf("MAP DATA OK!\n");
}

void	is_valid_file_name(char *file)
{
	while (*file != '\0' && (*(file) != '.'
			|| *(file + 1) == '.' || *(file + 1) == '/'))
		file++;
	if (ft_strncmp(file, ".cub", 5))
		ft_err("parsing :: invalid file name.");
}
