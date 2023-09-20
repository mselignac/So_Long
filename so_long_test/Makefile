# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mseligna <mseligna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 13:27:32 by mseligna          #+#    #+#              #
#    Updated: 2021/12/22 14:49:01 by mseligna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	srcs/main.c \
		srcs/check_file.c \
		srcs/check_file_2.c \
		srcs/errors.c \
		srcs/map_loop.c \
		srcs/player_moves.c \
		srcs/get_textures.c \
		utils/get_next_line.c \
		utils/mlx_utils.c

OBJS = ${SRCS:.c=.o}

NAME_BONUS = so_long_bonus

SRCS_BONUS =	srcs/main.c \
				srcs/check_file.c \
				srcs/check_file_2.c \
				srcs/errors.c \
				bonus/get_textures_bonus.c \
				bonus/map_loop_bonus.c \
				bonus/player_moves_bonus.c \
				bonus/print_bonus.c \
				utils/get_next_line.c \
				utils/ft_itoa.c \
				utils/mlx_utils.c

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

INCLUDE = -I/includes/so_long.h

PATH_MLX = minilibx-linux

LIB = minilibx-linux/libmlx_Linux.a -I./usr/include -L minilibx-linux -Lmlx_linux -Imlx_linux -lXext -lX11 -lm

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: ${NAME}

${NAME}: ${OBJS} ./includes/so_long.h
	make -C $(PATH_MLX)
	${CC} ${CFLAGS} ${OBJS} ${INCLUDE} ${LIB} -o ${NAME}

${NAME_BONUS}: ${OBJS_BONUS} ./includes/so_long.h
	make -C $(PATH_MLX)
	${CC} ${CFLAGS} ${OBJS_BONUS} ${INCLUDE} ${LIB} -o ${NAME_BONUS}

bonus: ${NAME_BONUS}

clean:
	make -C $(PATH_MLX) clean
	rm -f ${OBJS} ${OBJS_BONUS}

fclean: clean
	make -C $(PATH_MLX) clean
	rm -f ${NAME} ${NAME_BONUS}

re: fclean all

.PHONY: all clean fclean re