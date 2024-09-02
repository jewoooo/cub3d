/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:50:05 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/02 16:15:08 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void	init_buff(t_cub3d *info)
{
	int	i;

	i = -1;
	while (++i < S_HEIGHT)
		ft_memset(info->buff[i], 0, sizeof(int) * S_WIDTH);
}

void	init_walls(t_cub3d *info)
{
	int	i;

	i = -1;
	while (++i < 4)
		info->map_data.walls[i] = ft_calloc(T_HEIGHT * T_WIDTH, sizeof(int));
}

void	init_info(t_cub3d *info)
{
	int	i;

	info->mlx = mlx_init();
	if (!info->mlx)
		ft_err("init :: mlx obj create failed..");
	info->map_data.map = NULL;
	info->map_data.start = 0;
	info->map_data.width = 0;
	info->map_data.height = 0;
	i = 0;
	while (i < 3)
	{
		info->map_data.floor[i] = -1;
		info->map_data.ceil[i] = -1;
		i++;
	}
	init_buff(info);
	init_walls(info);
	info->data = ft_calloc(1, sizeof(t_img));
	if (!info->data)
		ft_err("init :: failed malloc (t_img).");
}

int	main(int argc, char **argv)
{
	t_cub3d	info;

	if (argc != 2)
		ft_err("no argument or more than 2 arguments.\n");
	init_info(&info);
	parsing(&info, argv[1]);
	execute(&info);
}
