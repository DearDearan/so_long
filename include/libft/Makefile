# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/17 10:44:35 by lifranco          #+#    #+#              #
#    Updated: 2025/12/20 15:41:18 by lifranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Werror -Wextra

OBJECTS = ft_strlcat.o\
	ft_bzero.o\
	ft_memmove.o\
	ft_memcpy.o\
	ft_tolower.o\
	ft_memcmp.o\
	ft_strnstr.o\
	ft_calloc.o\
	ft_isalpha.o\
	ft_isdigit.o\
	ft_isalnum.o\
	ft_isascii.o\
	ft_isprint.o\
	ft_strchr.o\
	ft_strrchr.o\
	ft_strncmp.o\
	ft_memchr.o\
	ft_atoi.o\
	ft_strdup.o\
	ft_strlen.o\
	ft_memset.o\
	ft_strlcpy.o\
	ft_toupper.o\
	ft_strdup.o\
	ft_substr.o\
	ft_strjoin.o\
	ft_strtrim.o\
	ft_split.o\
	ft_putchar_fd.o\
	ft_putstr_fd.o\
	ft_strmapi.o\
	ft_striteri.o\
	ft_putendl_fd.o\
	ft_putnbr_fd.o\
	ft_itoa.o\

BONUS = \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

all: $(NAME)

BONUS_OBJS = $(BONUS:.c=.o)

bonus: $(OBJECTS) $(BONUS_OBJS)
	ar rsc $(NAME) $(OBJECTS) $(BONUS_OBJS)

$(NAME): $(OBJECTS)
	ar rsc  $(NAME) $(OBJECTS)

%.o : %.c
	cc $(FLAGS) -o $@ -c $<
	

clean:
	rm -f $(OBJECTS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re