/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:56:54 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/27 16:01:03 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	test_map_array(t_map_data *map_data, t_tile_type **map)
{
	(void)map_data;
	int	i = 0;
	
	while (i < map_data->height + 2)
	{
		ft_printf("%d", i);
		// 2 | 0 -> 2개
		for (int a = map_data->height / 10 + 1; a > i / 10; a--)
			ft_printf(" ");
		ft_printf("[");
		int	j = 0;
		while (j < map_data->width + 2)
		{
			if (map[i][j] == EMPTY)
				ft_printf("  ");
			else if (map[i][j] == GROUND)
				ft_printf("0 ");
			else if (map[i][j] == WALL)
				ft_printf("1 ");
			else if (map[i][j] == START)
				ft_printf("N ");
			j++;
		}
		ft_printf("]\n");
		i++;
	}
}

int	quick_open_file(char *file, int line)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_err("parsing :: failed open file. (invalid path)");
	while (1 < line)
	{
		free(get_next_line(fd));
		line--;
	}
	return (fd);
}

char	*remove_space(char *src)
{
	while (*src)
	{
		if (*src != ' ')
			break ;
		src++;
	}
	return (src);
}
