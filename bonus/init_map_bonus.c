/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:31:14 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/21 10:52:09 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	set_background(t_bonus *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < ft_tablen(data->map))
	{
		j = 0;
		while (j < ft_linelen(data->map[i]))
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->img.img_0, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

static void	set_items(t_bonus *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < ft_tablen(data->map))
	{
		j = 0;
		while (j < ft_linelen(data->map[i]))
		{
			if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->img.img_p,
					j * TILE_SIZE, i * TILE_SIZE);
			if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->img.img_e,
					j * TILE_SIZE, i * TILE_SIZE);
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->img.img_c,
					j * TILE_SIZE, i * TILE_SIZE);
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img.img_1,
					j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

static void	set_enemy(t_bonus *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < ft_tablen(data->map))
	{
		j = 0;
		while (j < ft_linelen(data->map[i]))
		{
			if (data->map[i][j] == 'Z')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->img.img_z,
					j * TILE_SIZE, i * TILE_SIZE);
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	set_images(t_bonus *data)
{
	data->img.img_0 = mlx_xpm_file_to_image(data->mlx, "./xpm/herbe100.xpm",
			&data->img.img_width, &data->img.img_height);
	if (!data->img.img_0)
		error_img(data);
	data->img.img_p = mlx_xpm_file_to_image(data->mlx, "./xpm/psg100.xpm",
			&data->img.img_width, &data->img.img_height);
	if (!data->img.img_p)
		error_img(data);
	data->img.img_e = mlx_xpm_file_to_image(data->mlx, "./xpm/exit100.xpm",
			&data->img.img_width, &data->img.img_height);
	if (!data->img.img_e)
		error_img(data);
	data->img.img_c = mlx_xpm_file_to_image(data->mlx, "./xpm/om100.xpm",
			&data->img.img_width, &data->img.img_height);
	if (!data->img.img_c)
		error_img(data);
	data->img.img_1 = mlx_xpm_file_to_image(data->mlx, "./xpm/wall100.xpm",
			&data->img.img_width, &data->img.img_height);
	if (!data->img.img_1)
		error_img(data);
	data->img.img_z = mlx_xpm_file_to_image(data->mlx, "./xpm/enemy100.xpm",
			&data->img.img_width, &data->img.img_height);
	if (!data->img.img_z)
		error_img(data);
}

void	init_map_bonus(t_bonus *data)
{
	data->count = 0;
	data->i = 0;
	data->j = 0;
	data->game_won = 0;
	data->img.img_0 = 0;
	data->img.img_p = 0;
	data->img.img_e = 0;
	data->img.img_c = 0;
	data->img.img_1 = 0;
	data->img.img_z = 0;
	data->img.img_height = TILE_SIZE;
	data->img.img_width = TILE_SIZE;
	set_images(data);
	set_background(data);
	set_items(data);
	set_enemy(data);
}
