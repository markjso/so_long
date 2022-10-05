# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarks <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 12:24:36 by jmarks            #+#    #+#              #
#    Updated: 2022/10/05 10:59:02 by jmarks           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MLX_DIR = mlx

SRCS = srcs/so_long.c \
	srcs/movement.c \
	srcs/utils.c \
	srcs/render_map.c \
	srcs/checks.c \
	srcs/checks2.c \
	srcs/get_next_line.c \
	srcs/get_next_line_utils.c
	
OBJS=$(SRCS:.c=.o)

CC=gcc

CFLAGS=-Wall -Wextra -Werror -Iinc/

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
