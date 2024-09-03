/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:46:44 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/02 22:28:29 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	*load_xpm(t_cub3d *info, char *path, int size)
{
	void	*xpm;

	path = ft_strcut(path, 0, ft_strlen(path) - 1);
	ft_printf("load xpm path : [%s]\n", path);
	xpm = mlx_xpm_file_to_image(info->mlx, path, &size, &size);
	if (!xpm)
		ft_err("parsing :: failed load to xpm file. (invalid path)");
	free(path);
	return (xpm);
}

void	load_image(t_cub3d *info, int *wall, char *path, t_img *img)
{
	int	size;
	int	i;
	int	j;

	size = T_WIDTH;
	img->img = load_xpm(info, path, size);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->line_len, &img->endian);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			wall[i * size + j] = img->addr[i * size + j];
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_cub3d *info)
{
	load_image(info, info->map_data.texture[NO], "./textures/NO.xpm", info->data);
	load_image(info, info->map_data.texture[SO], "./textures/SO.xpm", info->data);
	load_image(info, info->map_data.texture[WE], "./textures/WE.xpm", info->data);
	load_image(info, info->map_data.texture[EA], "./textures/EA.xpm", info->data);
}
