# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 14:59:22 by mboukadi          #+#    #+#              #
#    Updated: 2023/10/08 13:36:38 by nicolas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_LIBFT = $ 	ft_isdigit.c ft_isprint.c ft_atoi.c ft_tolower.c ft_bzero.c \
			ft_strlen.c ft_toupper.c ft_isalnum.c ft_memcpy.c ft_memcmp.c \
			ft_strncmp.c ft_isalpha.c ft_isascii.c ft_strdup.c ft_memset.c \
			ft_memmove.c ft_strlcpy.c ft_strchr.c ft_strrchr.c \
			ft_memchr.c ft_strnstr.c ft_strlcat.c ft_putstr_fd.c \
			ft_putnbr_fd.c ft_putendl_fd.c ft_calloc.c ft_substr.c ft_strmapi.c\
			ft_strjoin.c ft_strtrim.c ft_striteri.c ft_itoa.c ft_split.c \
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
			printf/ft_printf.c printf/ft_putchar.c printf/ft_printhexnbr.c\
			printf/ft_printnbr.c printf/ft_printstr.c printf/ft_printunsnbr.c\
			printf/ft_putchar_fd.c printf/ft_printunsnbr.c \

SRCS_B =	ft_lstadd_front.c ft_lstnew.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

OBJS = $(SRCS_LIBFT:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all : ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

bonus:	${OBJS} ${OBJS_B}
		ar rcs ${NAME} ${OBJS} ${OBJS_B}

all:	${NAME}

clean:
		${RM} ${OBJS} ${OBJS_B}

fclean:	clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus