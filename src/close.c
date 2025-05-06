/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:38:49 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/18 17:24:26 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *data)
{
	free_tab(data->map);
	mlx_destroy_image(data->mlx, data->img.img_0);
	mlx_destroy_image(data->mlx, data->img.img_p);
	mlx_destroy_image(data->mlx, data->img.img_e);
	mlx_destroy_image(data->mlx, data->img.img_c);
	mlx_destroy_image(data->mlx, data->img.img_1);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}
