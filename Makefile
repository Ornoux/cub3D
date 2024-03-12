# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npatron <npatron@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 14:20:24 by npatron           #+#    #+#              #
#    Updated: 2024/03/12 14:39:54 by npatron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SOURCES = src/main.c \
      src/utils/get_next_line_utils.c \
      src/utils/get_next_line.c \
      src/utils/utils.c \
      src/parsing/parsing_arg.c \
      src/parsing/parsing_colors.c \
      src/parsing/parsing_textures.c \
      src/parsing/parsing_map.c \
      src/parsing/parsing.c \
      src/utils/utils_2.c \
      src/utils/utils_3.c \
      src/utils/lil_atoi.c \
      src/utils/ft_split.c \
      src/utils/utils_4.c \
      src/utils/utils_5.c \
      src/mlx/init_mlx.c \
      src/mlx/mlx_utils.c \

NAME     = cub3d
OBJECTS  = ${SOURCES:.c=.o}

MLX_PATH = ./minilibx
MLX      = $(MLX_PATH)/libmlx.a

CFLAGS     = -Wall -Wextra -Werror #-g -fsanitize=address
LDFLAGS    = -L ${MLX_PATH} -lm -lbsd -lX11 -lXext -lmlx


.c.o:
	clang $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): ${MLX} ${OBJECTS}
	clang $(CFLAGS) ${OBJECTS} $(LDFLAGS) -o $(NAME) ./minilibx/libmlx.a

all: $(NAME)


$(MLX):
	make -C $(MLX_PATH) all

clean:
	make -C $(MLX_PATH) clean
	rm -f ${OBJECTS}

fclean: clean
	rm -f $(NAME)

re: fclean all

