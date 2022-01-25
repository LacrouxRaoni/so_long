# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/22 15:02:38 by rruiz-la          #+#    #+#              #
#    Updated: 2022/01/25 20:39:46 by rruiz-la         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

PATH_LIBFT	=	./lib/libft
LIBFT		=	$(PATH_LIBFT)/libft.a 

PATH_MLX	=	./lib/minilibx
MLX 		=	$(PATH_MLX)/libmlx.a

I_OBJ	=	-I ./ -I ./lib/minilibx/ -I ./lib/libft/
LINKS	=	-I ./ -I ./lib/minilibx/ -L./lib/minilibx/ -lmlx -I ./lib/libft/ -L./lib/libft/ -lft

CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror
MLXFLAG	= -L. -lXext -L. -lX11 -L. -lm

SRC_DIR =	src
SRC_FILES	=	so_long.c \
				move_player.c \
				key_events.c \
				map_settings.c \
				quit_game.c \
				arrange_map.c \
				player_position.c \
				matrix_creation.c \
				image_settings.c \
				display_settings.c

SRC	= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR = obj
OBJ	=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

HEADER	=	so_long.h

FS	=	-g3

all:	$(NAME)

$(NAME):	 $(LIBFT) $(MLX) $(OBJ_DIR) $(OBJ) $(HEADER)
	$(CC) $(FS) $(CFLAGS) $(FS) $(OBJ) $(MLXFLAG) $(LINKS) -o $(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(I_OBJ)

$(LIBFT):
	make -C $(PATH_LIBFT)

$(MLX):
	make -C $(PATH_MLX)

$(OBJ_DIR):
	mkdir obj


clean:	
	rm -rf $(OBJ)
	rm -rf $(OBJ_DIR)
	make -C $(PATH_LIBFT) clean
	make -C $(PATH_MLX) clean

fclean:
	rm -rf $(NAME)
	make -C $(PATH_LIBFT) fclean

re: fclean all

valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./so_long map/map.ber

.PHONY:	all clean fclean re valgrind
