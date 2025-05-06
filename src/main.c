/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:54:22 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/20 18:20:44 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	**map;

	if (ac != 2)
		error("Il doit y avoir 1 argument", NULL);
	if (!is_filename(av[1]))
		error("Extension invalide", NULL);
	map = content_file_to_tab(av[1]);
	if (!map)
		return (1);
	map_is_valid(map);
	if (so_long(map))
		return (0);
	return (1);
}
