# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lifranco <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 02:21:10 by lifranco          #+#    #+#              #
#    Updated: 2025/11/10 16:41:37 by lifranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
OBJECTS = ft_printf.o\
		ft_putpointer.o\
		ft_putlunbr.o\
		ft_putlnbrhex.o\
		ft_putlnbr_fd.o\
		ft_putlchar_fd.o\
		ft_putlstr_fd.o\
		
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rsc $(NAME) $(OBJECTS)

%.o : %.c
	cc $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
