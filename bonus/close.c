/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:38:49 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/21 10:51:15 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	error_img(t_bonus *data)
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

int	close_window(t_bonus *data)
{
	free_tab(data->map);
	mlx_destroy_image(data->mlx, data->img.img_0);
	mlx_destroy_image(data->mlx, data->img.img_p);
	mlx_destroy_image(data->mlx, data->img.img_e);
	mlx_destroy_image(data->mlx, data->img.img_c);
	mlx_destroy_image(data->mlx, data->img.img_1);
	mlx_destroy_image(data->mlx, data->img.img_z);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}
