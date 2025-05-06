/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:28:44 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/23 08:59:26 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_player(t_bonus *data)
{
	data->i = 0;
	while (data->map[data->i])
	{
		data->j = 0;
		while (data->map[data->i][data->j])
		{
			if (data->map[data->i][data->j] == 'P')
				return ;
			data->j++;
		}
		data->i++;
	}
}

void	move_from_e(t_bonus *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
		data->j * TILE_SIZE, data->i * TILE_SIZE);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_e,
		data->j * TILE_SIZE, data->i * TILE_SIZE);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
		j * TILE_SIZE, i * TILE_SIZE);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_p,
		j * TILE_SIZE, i * TILE_SIZE);
	data->count++;
	ft_printf("%d\n", data->count);
	data->i = i;
	data->j = j;
	return ;
}

void	move_from_other(t_bonus *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_p,
		j * TILE_SIZE, i * TILE_SIZE);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
		data->j * TILE_SIZE, data->i * TILE_SIZE);
	if (data->map[data->i][data->j] == 'C')
		data->collect--;
	data->map[data->i][data->j] = '0';
	data->count++;
	ft_printf("%d\n", data->count);
	if (get_collectible(data->map) == 0)
			data->game_won = 1;
	if (data->map[i][j] == 'E')
		check_exit(data);
	data->i = i;
	data->j = j;
	return ;
}
