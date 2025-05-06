/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:09:56 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/20 16:23:28 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_pos_enemy(t_bonus *data)
{
	data->enemy_i = 0;
	while (data->map[data->enemy_i])
	{
		data->enemy_j = 0;
		while (data->map[data->enemy_i][data->enemy_j])
		{
			if (data->map[data->enemy_i][data->enemy_j] == 'Z')
				return ;
			data->enemy_j++;
		}
		data->enemy_i++;
	}
}

void	get_prev_enemy(t_bonus *data)
{
	data->prev_enemy_i = data->enemy_i;
	data->prev_enemy_j = data->enemy_j;
}

static void	check_player_behind(t_bonus *data)
{
	if (data->prev_enemy_i == data->i && data->prev_enemy_j == data->j)
		mlx_put_image_to_window(data->mlx, data->win, data->img.img_p,
			data->j * TILE_SIZE, data->i * TILE_SIZE);
}

void	check_enemy_behind(t_bonus *data)
{
	if (data->enemy_i == data->prev_i && data->enemy_j == data->prev_j)
		mlx_put_image_to_window(data->mlx, data->win, data->img.img_z,
			data->enemy_j * TILE_SIZE, data->enemy_i * TILE_SIZE);
	check_player_behind(data);
}

void	init_value(t_bonus *data)
{
	data->count = 0;
	data->prev_i = 0;
	data->prev_j = 0;
	data->i = 0;
	data->j = 0;
	data->game_won = 0;
	data->game_lose = 0;
	data->prev_enemy_i = 0;
	data->prev_enemy_j = 0;
	data->enemy_i = 0;
	data->enemy_j = 0;
	data->enemy_direction = 0;
}
