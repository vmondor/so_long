/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:51:59 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/18 20:10:09 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_enemy(t_bonus *data)
{
	if (data->enemy_direction == 0
		&& data->map[data->enemy_i - 1][data->enemy_j] != '1')
		move_enemy_up(data);
	else if (data->enemy_direction == 0
		&& data->map[data->enemy_i - 1][data->enemy_j] == '1')
		data->enemy_direction = -1;
	if (data->enemy_direction == -1
		&& data->map[data->enemy_i + 1][data->enemy_j] != '1')
		move_enemy_down(data);
	else if (data->enemy_direction == -1
		&& data->map[data->enemy_i + 1][data->enemy_j] == '1')
		data->enemy_direction = 1;
	if (data->enemy_direction == 1
		&& data->map[data->enemy_i][data->enemy_j - 1] != '1')
		move_enemy_left(data);
	else if (data->enemy_direction == 1
		&& data->map[data->enemy_i][data->enemy_j - 1] == '1')
		data->enemy_direction = 2;
	if (data->enemy_direction == 2
		&& data->map[data->enemy_i][data->enemy_j + 1] != '1')
		move_enemy_right(data);
	else if (data->enemy_direction == 2
		&& data->map[data->enemy_i][data->enemy_j + 1] == '1')
		data->enemy_direction = 0;
}

void	move_enemy_from_e(t_bonus *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_z,
		j * TILE_SIZE, i * TILE_SIZE);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
		data->enemy_j * TILE_SIZE, data->enemy_i * TILE_SIZE);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_e,
		data->enemy_j * TILE_SIZE, data->enemy_i * TILE_SIZE);
	data->enemy_i = i;
	data->enemy_j = j;
}

void	move_enemy_from_c(t_bonus *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_z,
		j * TILE_SIZE, i * TILE_SIZE);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
		data->enemy_j * TILE_SIZE, data->enemy_i * TILE_SIZE);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_c,
		data->enemy_j * TILE_SIZE, data->enemy_i * TILE_SIZE);
	data->enemy_i = i;
	data->enemy_j = j;
}

void	move_enemy_from_other(t_bonus *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_z,
		j * TILE_SIZE, i * TILE_SIZE);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
		data->enemy_j * TILE_SIZE, data->enemy_i * TILE_SIZE);
		data->enemy_i = i;
		data->enemy_j = j;
}
