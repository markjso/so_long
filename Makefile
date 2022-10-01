# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarks <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 12:24:36 by jmarks            #+#    #+#              #
#    Updated: 2022/10/01 19:10:51 by jmarks           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MLX_DIR = mlx

SRCS = sources/so_long.c \
	sources/movement.c \
	sources/utils.c \
	sources/render_map.c \
	sources/checks.c \
	sources/checks2.c \
	sources/get_next_line.c \
	sources/get_next_line_utils.c
	
OBJS=$(SRCS:.c=.o)

CC=gcc

CFLAGS=-Wall -Wextra -Werror -Iinc/ -g

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./mlx 2>/dev/null
	$(CC) $(CLFAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all	clean fclean re
