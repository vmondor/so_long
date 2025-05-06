/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:34:17 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/18 17:26:15 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/get_next_line.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_stash_to_line(char *stash)
{
	int		i;
	char	*line;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_clean_stash(char *stash)
{
	int		len;
	int		i;
	char	*temp;

	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (!stash[len])
	{
		free(stash);
		return (NULL);
	}
	len++;
	temp = malloc(sizeof(char) * (ft_strlen(stash) - len + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (stash[len])
		temp[i++] = stash[len++];
	temp[i] = '\0';
	free(stash);
	return (temp);
}

char	*ft_read_and_stash(int fd, char *stash, int nb_char)
{
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr(stash, '\n') && nb_char != 0)
	{
		nb_char = read(fd, buf, BUFFER_SIZE);
		if (nb_char == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[nb_char] = '\0';
		if (!stash)
		{
			stash = malloc(sizeof(char) * (nb_char + 1));
			stash = ft_strcpy(stash, buf);
		}
		else
			stash = ft_strjoin(stash, buf);
	}
	free (buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;
	int				nb_char;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nb_char = 1;
	stash = ft_read_and_stash(fd, stash, nb_char);
	if (!stash)
		return (NULL);
	line = ft_stash_to_line(stash);
	stash = ft_clean_stash(stash);
	if (line[0] == '\0')
	{
		free(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
