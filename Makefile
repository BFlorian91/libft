# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 14:08:19 by flbeaumo          #+#    #+#              #
#    Updated: 2019/01/10 14:29:28 by flbeaumo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
NAME = libft.a

SRCS = ft_strlen.c ft_memset.c ft_bzero.c ft_strcmp.c ft_memcpy.c \
	   ft_memccpy.c ft_putchar.c ft_putstr.c ft_isascii.c \
	   ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
	   ft_strchr.c ft_strrchr.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
	   ft_isdigit.c ft_isalnum.c ft_isprint.c ft_toupper.c \
	   ft_tolower.c ft_memcmp.c ft_memchr.c ft_strstr.c ft_strnstr.c \
	   ft_memmove.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putnbr_fd.c ft_putendl_fd.c ft_putendl.c ft_memalloc.c \
	   ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
	   ft_striteri.c ft_strmap.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	   ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_is_space.c ft_strsplit.c \
	   ft_strclen.c ft_strndup.c ft_strlcat.c ft_itoa.c ft_lstnew.c \
	   ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	   ft_power.c ft_print_words_tables.c ft_lstlen.c get_next_line.c \

OBJ = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $^
	@ranlib $(NAME)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

