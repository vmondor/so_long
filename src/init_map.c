/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:31:14 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/21 10:53:36 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_background(t_data *data)
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

static void	set_items(t_data *data)
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

void	init_value(t_data *data)
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
	data->img.img_height = TILE_SIZE;
	data->img.img_width = TILE_SIZE;
}

static int	error_img(t_data *data)
{
	ft_printf("Image not found\n");
	free_tab(data->map);
	if (data->img.img_0 != 0)
		mlx_destroy_image(data->mlx, data->img.img_0);
	if (data->img.img_p != 0)
		mlx_destroy_image(data->mlx, data->img.img_p);
	if (data->img.img_e != 0)
		mlx_destroy_image(data->mlx, data->img.img_e);
	if (data->img.img_c != 0)
		mlx_destroy_image(data->mlx, data->img.img_c);
	if (data->img.img_1 != 0)
		mlx_destroy_image(data->mlx, data->img.img_1);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

void	init_map(t_data *data)
{
	data->img.img_0 = mlx_xpm_file_to_image(data->mlx, "./xpm/herbe100.xpm",
			&data->img.img_width, &data->img.img_height);
	if (data->img.img_0 == 0)
		error_img(data);
	data->img.img_p = mlx_xpm_file_to_image(data->mlx, "./xpm/psg100.xpm",
			&data->img.img_width, &data->img.img_height);
	if (data->img.img_p == 0)
		error_img(data);
	data->img.img_e = mlx_xpm_file_to_image(data->mlx, "./xpm/exit100.xpm",
			&data->img.img_width, &data->img.img_height);
	if (data->img.img_e == 0)
		error_img(data);
	data->img.img_c = mlx_xpm_file_to_image(data->mlx, "./xpm/om100.xpm",
			&data->img.img_width, &data->img.img_height);
	if (data->img.img_c == 0)
		error_img(data);
	data->img.img_1 = mlx_xpm_file_to_image(data->mlx, "./xpm/wall100.xpm",
			&data->img.img_width, &data->img.img_height);
	if (data->img.img_1 == 0)
		error_img(data);
	set_background(data);
	set_items(data);
}
