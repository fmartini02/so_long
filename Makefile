# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francema <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 19:00:17 by fmartini          #+#    #+#              #
#    Updated: 2025/01/22 19:06:52 by francema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c \
	check_border_map.c \
	cordinates_stuff.c \
	direction_moves.c \
	map_utils.c \
	keycodes.c \
	map_generator.c \
	map_validation.c \
	mem_destroyer.c \
	tex_loading.c \
	specific_tex.c \

LIBFT = libft/libft.a

OBJS = ${SRC:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

MLX = minilibx-linux/libmlx.a

LINKER_FLAG = -Lminilibx-linux -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LINKER_FLAG) $(LIBFT) -o $@

$(MLX):
	make -C ./mlx

$(LIBFT):
	@make -s -C ./libft

%.o: %.c
	@ $(CC) $(CFLAGS)  -c  $< -o $@

clean:
	@/bin/rm -f *.o
	@make -s -C libft clean

fclean: clean
	@/bin/rm -f $(NAME)
	@rm -f $(LIBFT)

re : fclean all

.PHONY: clean fclean re
