/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:02:46 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/21 10:46:45 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define KEY_UP 119
# define KEY_DOWN 115
# define KEY_LEFT 97
# define KEY_RIGHT 100
# define ESC 65307
# define WIDTH 2500
# define HEIGHT 1300
# define TILE_SIZE 100

# include "../mlx/mlx.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../src/get_next_line.h"
# include <unistd.h> // write
# include <stdlib.h> // malloc
# include <X11/X.h>
# include <fcntl.h> // open

typedef struct s_img
{
	void	*img_0;
	void	*img_p;
	void	*img_e;
	void	*img_c;
	void	*img_1;
	void	*img_z;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_bonus
{
	void	*mlx;
	void	*win;
	char	**map;
	int		count;
	int		prev_i;
	int		prev_j;
	int		i;
	int		j;
	int		game_won;
	int		game_lose;
	int		prev_enemy_i;
	int		prev_enemy_j;
	int		enemy_i;
	int		enemy_j;
	int		enemy_direction;
	int		collect;
	t_img	img;
}				t_bonus;

/* FILE_TO_TAB */
char	**content_file_to_tab(char *str);

/* GET_ITEMS */
char	**get_map(char **map);
int		get_collectible(char **map);
int		get_exit(char **map);

/* CHECK_MAP_UTILS */
int		ft_strcmp(char *s1, char *s2);
int		is_rectangle(char **map);
int		is_close(char **map);
int		more_items(char **tab);
int		correct_items_in_map(char **tab);

/* CHECK MAP */
void	map_is_valid(char **map);

/* UTILS */
int		is_filename(char *filename);
int		ft_strlen(char *s);
int		ft_linelen(char *s);
int		ft_tablen(char **tab);
void	free_tab(char **tab);

/* ERROR */
void	error(char *str, char **tab);

/***** GAME *****/
int		so_long(char **map);

/* CLOSE */
int		error_img(t_bonus *data);
int		close_window(t_bonus *data);

/* SO_LONG */
void	init_map(t_bonus *data);
void	init_value(t_bonus *data);

/* MOVE_UTILS*/
void	get_player(t_bonus *data);
void	get_prev_enemy(t_bonus *data);
void	get_pos_enemy(t_bonus *data);
void	move_from_e(t_bonus *data, int i, int j);
void	move_from_other(t_bonus *data, int i, int j);

/* MOVE_ENEMY */
void	move_enemy_up(t_bonus *data);
void	move_enemy_down(t_bonus *data);
void	move_enemy_left(t_bonus *data);
void	move_enemy_right(t_bonus *data);
void	check_enemy_behind(t_bonus *data);

void	move_enemy_from_e(t_bonus *data, int i, int j);
void	move_enemy_from_c(t_bonus *data, int i, int j);
void	move_enemy_from_other(t_bonus *data, int i, int j);

/* GAME */
void	display_count(t_bonus *data);
void	move_player(t_bonus *data, int keycode);
void	check_exit(t_bonus *data);
void	teleport_enemy(t_bonus *data);
void	lose(t_bonus *data);

int		more_items_enemy(char **tab);
int		correct_items_in_map_enemy(char **tab);
void	init_map_bonus(t_bonus *data);
void	move_enemy(t_bonus *data);

#endif