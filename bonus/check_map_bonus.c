/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:12:36 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/20 18:54:39 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	flood_fill(char **map, int x, int y)
{
	if (map[x][y] == 'P' || map[x][y] == 'C' || map[x][y] == '0'
		|| map[x][y] == 'E' || map[x][y] == 'Z')
	{
		map[x][y] = 'A';
		flood_fill(map, x, y + 1);
		flood_fill(map, x, y - 1);
		flood_fill(map, x + 1, y);
		flood_fill(map, x - 1, y);
	}
}

static void	start_flood_fill(char **map_copy)
{
	int	index;
	int	j;

	index = 0;
	j = 0;
	while (map_copy[index])
	{
		j = 0;
		while (map_copy[index][j])
		{
			if (map_copy[index][j] == 'P')
			{
				flood_fill(map_copy, index, j);
				return ;
			}
			j++;
		}
		index++;
	}
}

static int	check_flood_fill(char **map)
{
	char	**map_copy;

	map_copy = get_map(map);
	if (!map_copy)
		return (0);
	start_flood_fill(map_copy);
	if (get_collectible(map_copy) != 0)
	{
		free_tab(map_copy);
		return (0);
	}
	if (get_exit(map_copy) != 0)
	{
		free_tab(map_copy);
		return (0);
	}
	free_tab(map_copy);
	return (1);
}

void	map_is_valid(char **map)
{
	if (!map)
		error(NULL, NULL);
	if (is_rectangle(map) == 0)
		error("ce n'est pas rectangle", map);
	if (!is_close(map))
		error("la map n'est pas fermee", map);
	if (more_items(map))
		error("les items ne sont pas bon", map);
	if (more_items_enemy(map))
		error("Il faut un ennemi dans la map", map);
	if (!correct_items_in_map_enemy(map))
		error("Des items sont incorrects", map);
	if (!check_flood_fill(map))
		error("Des items sont bloquer", map);
	if (ft_tablen(map) * TILE_SIZE > HEIGHT
		|| ft_linelen(map[0]) * TILE_SIZE > WIDTH)
		error("Map trop grande", map);
}
