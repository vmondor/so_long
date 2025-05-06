/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:35:23 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/18 13:42:57 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data)
{
	if (data->map[data->i - 1][data->j] != '1')
	{
		if (data->map[data->i][data->j] == 'E')
			move_from_e(data, data->i - 1, data->j);
		else
			move_from_other(data, data->i - 1, data->j);
	}
}

void	move_down(t_data *data)
{
	if (data->map[data->i + 1][data->j] != '1')
	{
		if (data->map[data->i][data->j] == 'E')
			move_from_e(data, data->i + 1, data->j);
		else
			move_from_other(data, data->i + 1, data->j);
	}
}

void	move_left(t_data *data)
{
	if (data->map[data->i][data->j - 1] != '1')
	{
		if (data->map[data->i][data->j] == 'E')
			move_from_e(data, data->i, data->j - 1);
		else
			move_from_other(data, data->i, data->j - 1);
	}
}

void	move_right(t_data *data)
{
	if (data->map[data->i][data->j + 1] != '1')
	{
		if (data->map[data->i][data->j] == 'E')
			move_from_e(data, data->i, data->j + 1);
		else
			move_from_other(data, data->i, data->j + 1);
	}
}

void	move_player(t_data *data, int keycode)
{
	if (keycode == KEY_UP)
		return (move_up(data));
	if (keycode == KEY_DOWN)
		return (move_down(data));
	if (keycode == KEY_LEFT)
		return (move_left(data));
	if (keycode == KEY_RIGHT)
		return (move_right(data));
}
