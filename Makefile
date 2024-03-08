# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npatron <npatron@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 14:20:24 by npatron           #+#    #+#              #
#    Updated: 2024/03/07 13:48:54 by npatron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = src/main.c \
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
	  
OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

.c.o:
	gcc $(CFLAGS) -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all