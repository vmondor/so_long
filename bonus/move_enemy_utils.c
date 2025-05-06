/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:51:38 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/18 17:50:37 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_enemy_up(t_bonus *data)
{
	if (data->map[data->enemy_i][data->enemy_j] == 'E')
		move_enemy_from_e(data, data->enemy_i - 1, data->enemy_j);
	else if (data->map[data->enemy_i][data->enemy_j] == 'C')
		move_enemy_from_c(data, data->enemy_i - 1, data->enemy_j);
	else
		move_enemy_from_other(data, data->enemy_i - 1, data->enemy_j);
}

void	move_enemy_down(t_bonus *data)
{
	if (data->map[data->enemy_i][data->enemy_j] == 'E')
		move_enemy_from_e(data, data->enemy_i + 1, data->enemy_j);
	else if (data->map[data->enemy_i][data->enemy_j] == 'C')
		move_enemy_from_c(data, data->enemy_i + 1, data->enemy_j);
	else
		move_enemy_from_other(data, data->enemy_i + 1, data->enemy_j);
}

void	move_enemy_left(t_bonus *data)
{
	if (data->map[data->enemy_i][data->enemy_j] == 'E')
		move_enemy_from_e(data, data->enemy_i, data->enemy_j - 1);
	else if (data->map[data->enemy_i][data->enemy_j] == 'C')
		move_enemy_from_c(data, data->enemy_i, data->enemy_j - 1);
	else
		move_enemy_from_other(data, data->enemy_i, data->enemy_j - 1);
}

void	move_enemy_right(t_bonus *data)
{
	if (data->map[data->enemy_i][data->enemy_j] == 'E')
		move_enemy_from_e(data, data->enemy_i, data->enemy_j + 1);
	else if (data->map[data->enemy_i][data->enemy_j] == 'C')
		move_enemy_from_c(data, data->enemy_i, data->enemy_j + 1);
	else
		move_enemy_from_other(data, data->enemy_i, data->enemy_j + 1);
}
