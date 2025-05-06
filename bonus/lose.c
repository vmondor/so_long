/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lose.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:06:02 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/20 16:41:54 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	lose(t_bonus *data)
{
	if (data->i == data->enemy_i && data->j == data->enemy_j)
	{
		ft_printf("Tu as perdu");
		close_window(data);
	}
	if (data->prev_i == data->enemy_i && data->prev_j == data->enemy_j
		&& data->i == data->prev_enemy_i && data->j == data->prev_enemy_j)
	{
		ft_printf("Tu as perdu");
		close_window(data);
	}
}
