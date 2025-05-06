/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:12:13 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/23 09:05:40 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_event_key(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_window(data);
	if (keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_RIGHT || keycode == KEY_LEFT)
		move_player(data, keycode);
	return (0);
}

int	so_long(char **map)
{
	t_data	data;

	init_value(&data);
	data.map = get_map(map);
	free_tab(map);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (0);
	data.win = mlx_new_window(data.mlx, ft_linelen(data.map[0]) * TILE_SIZE,
			ft_tablen(data.map) * TILE_SIZE, "./so_long");
	if (!data.win)
		return (free(data.mlx), 1);
	init_map(&data);
	get_player(&data);
	mlx_hook(data.win, KeyPress, KeyPressMask, ft_event_key, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask,
		&close_window, &data);
	mlx_loop(data.mlx);
	return (1);
}
