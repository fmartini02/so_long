# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmartini <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 19:00:17 by fmartini          #+#    #+#              #
#    Updated: 2023/06/22 08:50:33 by fmartini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c \
	set_list.c \
	tex_loading.c \
	valid_map.c \
	get_map.c \
	direction_moves.c \
	keycodes.c \
	specific_tex.c \
	check_border_map.c \
	mem_destroyer.c \
	flood_fill.c \
	ft_checks.c


LIBFT = libft/libft.a

OBJS = ${SRC:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g 

MLX = mlx/libmlx.a

LINKER_FLAG = -Lmlx -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LINKER_FLAG) $(LIBFT)  -o   $@

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