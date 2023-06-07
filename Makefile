# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmartini <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 19:00:17 by fmartini          #+#    #+#              #
#    Updated: 2023/06/05 19:16:54 by fmartini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c \
	set_list.c \
	tex_loading.c \
	valid_map.c \
	get_map.c \

LIBFT = libft/libft.a

OBJS = ${SRC:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

MLX = mlx/libmlx.a

LINKER_FLAG = -Lminilibx-linux -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(MLX):
	make -C ./mlx

$(LIBFT):
	make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS)  -c  $< -o $@

clean:
	/bin/rm -f *.o
	make -C libft clean
	make -C mlx clean

fclean: clean
	/bin/rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(MLX)

re : fclean all
