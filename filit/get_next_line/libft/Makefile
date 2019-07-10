# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwode <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/21 03:47:42 by zwode             #+#    #+#              #
#    Updated: 2019/05/09 17:13:29 by zwode            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDES = ./
FLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c ft_memccpy.c ft_strchr.c ft_strncmp.c \
	   ft_bzero.c ft_memchr.c ft_strclr.c ft_strncpy.c \
	   ft_memcmp.c ft_strcmp.c ft_strnequ.c \
	   ft_isalnum.c ft_memcpy.c ft_strcpy.c ft_strnew.c \
	   ft_isalpha.c ft_memdel.c ft_strdel.c ft_strnstr.c \
	   ft_isascii.c ft_memmove.c ft_strdup.c ft_strrchr.c \
	   ft_isdigit.c ft_memset.c ft_strequ.c ft_strsplit.c \
	   ft_isprint.c ft_putchar.c ft_striter.c ft_strstr.c \
	   ft_itoa.c ft_putchar_fd.c ft_striteri.c ft_strsub.c \
	   ft_putendl.c ft_strjoin.c ft_strtrim.c \
	   ft_putendl_fd.c ft_strlcat.c \
	   ft_putnbr.c ft_strlen.c \
	   ft_putnbr_fd.c ft_strmap.c ft_tolower.c \
	   ft_putstr.c ft_strmapi.c ft_toupper.c \
	   ft_putstr_fd.c \
	   ft_memalloc.c ft_strcat.c ft_strncat.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRCS) -I $(INCLUDES)
	ar rc $(NAME) $(OBJS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
