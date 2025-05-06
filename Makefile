# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 16:28:19 by vmondor           #+#    #+#              #
#    Updated: 2024/02/19 12:10:06 by vmondor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long
BONUS			= so_long_bonus

CC				= clang
INCLUDES		= -I/usr/include -Imlx
MLX_FLAGS		= -L./mlx -lmlx -L/usr/lib -I./mlx -lXext -lX11 -lm -lz
LIBFTPRINTF_DIR	= libft/ft_printf
LIBFTPRINTF		= $(LIBFTPRINTF_DIR)/libftprintf.a
CFLAGS			= -Wall -Werror -Wextra -g3
HEADERS			= $(SRC_PATH)so_long.h


SRC_PATH		= src/
OBJ_PATH		= src/obj/

SRC_PATH_BONUS	= bonus/
OBJ_PATH_BONUS	= bonus/obj/

SRC_FILES		=	main.c					\
					get_next_line_utils.c	\
					get_next_line.c			\
					file_to_tab.c			\
					utils.c					\
					error.c					\
					check_map.c				\
					check_map_utils.c		\
					get_items.c				\
					so_long.c				\
					close.c					\
					init_map.c				\
					move.c					\
					move_utils.c			\
					check_exit.c			\

SRC_FILES_BONUS	=	so_long_bonus.c			\
					get_next_line_utils.c	\
					get_next_line.c			\
					file_to_tab.c			\
					utils.c					\
					error.c					\
					check_map_bonus.c		\
					check_map_utils.c		\
					check_map_utils_bonus.c	\
					get_items.c				\
					close.c					\
					init_map_bonus.c		\
					move.c					\
					move_utils.c			\
					check_exit.c			\
					move_enemy.c			\
					move_enemy_utils.c		\
					ft_itoa.c				\
					lose.c					\
					enemy.c					\
					teleport_enemy.c		\

OBJ_FILES		= $(SRC_FILES:.c=.o)
OBJS			= $(addprefix $(OBJ_PATH), $(OBJ_FILES))
OBJ_FILES_BONUS	= $(SRC_FILES_BONUS:.c=.o)
OBJS_BONUS		= $(addprefix $(OBJ_PATH_BONUS), $(OBJ_FILES_BONUS))

all: mlx $(OBJ_PATH) ${NAME}

mlx:
	@$(MAKE) -C mlx

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(LIBFTPRINTF) $(OBJS)
	$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME) -L$(LIBFTPRINTF_DIR) -lftprintf

$(LIBFTPRINTF):
	$(MAKE) -C $(LIBFTPRINTF_DIR)

bonus : mlx $(OBJ_PATH_BONUS) ${BONUS}

$(OBJ_PATH_BONUS)%.o: $(SRC_PATH_BONUS)%.c $(HEADERS) bonus/so_long_bonus.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(OBJ_PATH_BONUS):
	mkdir $(OBJ_PATH_BONUS)

$(BONUS): $(LIBFTPRINTF) $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) $(MLX_FLAGS) -o $(BONUS) -L$(LIBFTPRINTF_DIR) -lftprintf

clean:
	rm -rf $(OBJ_PATH)
	rm -rf $(OBJ_PATH_BONUS)
	@$(MAKE) -C mlx clean
	$(MAKE) -C $(LIBFTPRINTF_DIR) clean

fclean: clean
	rm -f ${NAME}
	rm -f ${BONUS}
	@$(MAKE) -C mlx clean
	$(MAKE) -C $(LIBFTPRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re mlx
