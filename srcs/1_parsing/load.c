/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:46:44 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/27 12:31:59 by minhulee         ###   ########seoul.kr  */
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
