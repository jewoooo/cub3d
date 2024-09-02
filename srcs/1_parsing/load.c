/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:46:44 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/02 16:16:57 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	*load_xpm(t_cub3d *info, char *path, int size)
// {
// 	void	*xpm;

// 	path = ft_strcut(path, 0, ft_strlen(path) - 1);
// 	ft_printf("load xpm path : [%s]\n", path);
// 	xpm = mlx_xpm_file_to_image(info->mlx, path, &size, &size);
// 	if (!xpm)
// 		ft_err("parsing :: failed load to xpm file. (invalid path)");
// 	free(path);
// 	return (xpm);
// }

void	load_image(t_cub3d *info, int *wall, char *path, int size)
{
	int	i;
	int	j;

	path = ft_strcut(path, 0, ft_strlen(path) - 1);
	info->data->img = mlx_xpm_file_to_image(info->mlx, path, &size, &size);
	if (!info->data->img)
		ft_err("parsing :: failed load to xpm file. (invalid path)");
	info->data->addr = (int *)mlx_get_data_addr(info->data->img, &info->data->bpp,
			&info->data->line_len, &info->data->endian);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			wall[i * size + j] = info->data->addr[i * size + j];
	}
	mlx_destroy_image(info->mlx, info->data->img);
}
