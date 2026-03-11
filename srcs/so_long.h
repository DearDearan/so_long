/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 23:31:08 by lifranco          #+#    #+#             */
/*   Updated: 2026/03/11 17:47:01 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include "gnl/get_next_line.h"
# include <math.h>
# include <fcntl.h>
# include <X11/keysym.h>
# define T_SIZE 64

struct s_img
{
	int	imgw;
	int	imgh;
} ;

typedef union u_img
{
	int				mlximg;
	struct s_img	img;
}	t_img;

typedef struct s_game
{
	int		px;
	int		py;
	int		move_cnt;
	int		collect_cnt;
	char	**map;
	/* Window Management */
	void	*mlx;
	void	*img;	
	void	*win;
	int		bits;
	int		endian;
	int		llen;
	int		offset;
	char	*addr;
	int		frame;
	/* Texture Management */
	void	*wall_txtr;
	void	*floor_txtr;
	void	*player_txtr;
	void	*exit_txtr;
	void	*collectible_txtr;
	int		h;
	int		w;

	/* Tile Management */
	t_img	winimg;

}	t_game;

/* PARSING_C */
char	**create_map(char **argv, int argv_len, t_game *game);

/* CHECK_FILE_C */
int		check_file_length(char **map);
int		check_valid(char **map, int height);

/* CHECK_FILL_C */
void	find_player(char **map, int *x, int *y);
int		check_fill(char **map, int height);

/* CHECK_OTHER_C */
int		check_exit(char **map);

/* UTILS_C */
void	freemap(char **map);
void	render(t_game *game);
void	gnl_drain(int fd);
int		check_args(char **argv, int argv_len);
void	put_player_txtr(int key, t_game *game);

/* WINDOW_C */
int		closewin(t_game *game);
void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
int		init_window(t_game *game);
void	destroy_textures(t_game *game);

/* HANDLER_C */
int		key_handler(int key, t_game *game);
int		gamewin(t_game *game);

/* MOVE_C */
void	moveup(t_game *game);
void	movedown(t_game *game);
void	moveleft(t_game *game);
void	moveright(t_game *game);
void	handle(int key, t_game *game);

/* COLLECT_CNT_C */
int		count_collect_cnt(char **map);

/* DRAW_C */

void	draw_sprite(t_game *game, void *txtr, int x, int y);
#endif