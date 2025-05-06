/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:35:38 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/17 13:53:35 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	more_items_enemy(char **tab)
{
	int	i;

	int (count_z) = 0;
	int (index) = 0;
	while (tab[index])
	{
		i = 0;
		while (tab[index][i])
		{
			if (tab[index][i] == 'Z')
				count_z++;
			i++;
		}
		index++;
	}
	if (count_z != 1)
		return (1);
	return (0);
}

int	correct_items_in_map_enemy(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] && tab[i][j] != '\n')
		{
			if (tab[i][j] != '1' && tab[i][j] != '0' && tab[i][j] != 'P'
				&& tab[i][j] != 'E' && tab[i][j] != 'C' && tab[i][j] != 'Z')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
