/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teleport_enemy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:34:14 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/21 10:58:09 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	teleport_enemy(t_bonus *data)
{
	if ((data->collect == 5 || data->collect == 1)
		&& data->map[data->enemy_i][data->enemy_j] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
			data->enemy_j * TILE_SIZE, data->enemy_i * TILE_SIZE);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img_z,
			data->prev_j * TILE_SIZE, data->prev_i * TILE_SIZE);
		data->enemy_i = data->prev_i;
		data->enemy_j = data->prev_j;
	}
}
