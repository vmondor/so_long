/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_items.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:02:54 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/13 10:25:40 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(char **map)
{
	char	**get_map;
	int		j;

	int (i) = 0;
	get_map = malloc(sizeof(char *) * (ft_tablen(map) + 1));
	if (!get_map)
		return (NULL);
	while (map[i])
	{
		get_map[i] = malloc(sizeof(char) * (ft_linelen(map[i]) + 1));
		if (!get_map[i])
			return (NULL);
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			get_map[i][j] = map[i][j];
			j++;
		}
		get_map[i][j] = '\0';
		i++;
	}
	get_map[i] = NULL;
	return (get_map);
}

int	get_collectible(char **map)
{
	int	i;
	int	j;
	int	collect;

	if (!map)
		return (0);
	i = 0;
	collect = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				collect++;
			j++;
		}
		i++;
	}
	return (collect);
}

int	get_exit(char **map)
{
	int	i;
	int	j;

	if (!map)
		return (0);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
