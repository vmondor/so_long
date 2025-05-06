/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:35:38 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/13 17:28:56 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while ((s1[i] && s2[i]) && (s1[i] == s2[i]))
		i++;
	if (s1[i] || s2[i])
		return (0);
	return (1);
}

int	is_rectangle(char **map)
{
	int	nb_line;
	int	i;
	int	line_len;
	int	current_line_len;

	i = 0;
	nb_line = ft_tablen(map);
	line_len = ft_linelen(map[0]);
	current_line_len = 0;
	while (i < nb_line)
	{	
		current_line_len = ft_linelen(map[i]);
		if (line_len != current_line_len)
			return (0);
		i++;
	}
	return (1);
}

int	is_close(char **map)
{
	int	index;
	int	i;

	index = 0;
	i = 0;
	while (map[index])
	{
		i = 0;
		if (index == 0 || index == ft_tablen(map) - 1)
		{
			while (map[index][i] && map[index][i] != '\n')
			{
				if (map[index][i] != '1')
					return (0);
				i++;
			}
		}
		else
			if (map[index][0] != '1' ||
				map[index][ft_strlen(map[index]) - 2] != '1')
				return (0);
		index++;
	}
	return (1);
}

int	more_items(char **tab)
{
	int	i;

	int (count_p) = 0;
	int (count_e) = 0;
	int (count_c) = 0;
	int (index) = 0;
	while (tab[index])
	{
		i = 0;
		while (tab[index][i])
		{
			if (tab[index][i] == 'P')
				count_p++;
			if (tab[index][i] == 'E')
				count_e++;
			if (tab[index][i] == 'C')
				count_c++;
			i++;
		}
		index++;
	}
	if (count_p != 1 || count_e != 1 || count_c < 1)
		return (1);
	return (0);
}

int	correct_items_in_map(char **tab)
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
				&& tab[i][j] != 'E' && tab[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
