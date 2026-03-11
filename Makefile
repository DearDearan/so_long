# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
OBJ_DIR = obj
CFLAGS = -Wall -Wextra -Werror -I../include -Iminilibx-linux -I$(GNL_DIR) -g

SRC = srcs/main.c \
      srcs/parsing.c \
      srcs/utils.c \
      srcs/check_file.c \
      srcs/check_fill.c \
      srcs/check_other.c \
	  srcs/draw.c \
      srcs/window.c \
	  srcs/handler.c \
	  srcs/move.c \
	  srcs/collect_cnt.c \
      $(GNL_SRC)

# OBJ
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# LIBFT
LIBFT_DIR = include/libft
LIBFT = $(LIBFT_DIR)/libft.a

# GNL
GNL_DIR = include/gnl
GNL_SRC = $(GNL_DIR)/get_next_line.c \
          $(GNL_DIR)/get_next_line_utils.c

# MLX
MLX_DIR = include/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

# FT_PRINTF
PRINTF_DIR = include/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
 
INCLUDES = -Iinclude -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(MLX_DIR) -I$(PRINTF_DIR)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(PRINTF) \
	-lXext -lX11 -lm -lz -lbsd -lXrender -lXrandr -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
