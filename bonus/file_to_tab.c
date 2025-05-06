/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:35:15 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/21 10:53:08 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_count_line(char *filename)
{
	int		nb_line;
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error("Fichier inexistant", NULL);
	nb_line = 0;
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		error("Dossier ou fichier vide entrer en parametre", NULL);
	}
	while (line)
	{
		nb_line++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (nb_line);
}

static char	*ft_strdup(char *src)
{
	int		i;
	char	*str;

	if (!src)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	free(src);
	return (str);
}

static char	**get_file(char *filename, char **tab, int tab_index)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error("Fichier inexistant", NULL);
	line = get_next_line(fd);
	while (line)
	{
		tab[tab_index] = ft_strdup(line);
		line = get_next_line(fd);
		tab_index++;
	}
	close(fd);
	return (tab[tab_index] = NULL, tab);
}

char	**content_file_to_tab(char *filename)
{
	char	**tab;
	int		tab_index;
	int		count_line;

	count_line = ft_count_line(filename);
	tab = malloc(sizeof(char *) * (count_line + 1));
	if (!tab)
		return (NULL);
	tab_index = 0;
	return (get_file(filename, tab, tab_index));
}
