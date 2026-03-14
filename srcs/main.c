/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 23:43:09 by lifranco          #+#    #+#             */
/*   Updated: 2026/03/14 16:59:14 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	renderframe(void *data)
{
	t_game	*game;

	game = data;
	ft_memset(game->addr, 0, game->llen * game->winimg.img.imgh);
	render(game);
	if (game->player_txtr)
		draw_sprite(game, game->player_txtr,
			game->px * T_SIZE, game->py * T_SIZE);
	mlx_put_image_to_window(game->mlx,
		game->win, game->img, 0, 0);
	game->frame += 1;
	return (0);
}

static void	init_textures(t_game *game)
{
	int	tw;
	int	th;

	tw = T_SIZE;
	th = T_SIZE;
	game->player_txtr = mlx_xpm_file_to_image(game->mlx,
			"./textures/Player3.xpm", &tw, &th);
	game->collectible_txtr = mlx_xpm_file_to_image(game->mlx,
			"./textures/Collectible.xpm", &tw, &th);
	game->exit_txtr = mlx_xpm_file_to_image(game->mlx,
			"./textures/Exit.xpm", &tw, &th);
	game->floor_txtr = mlx_xpm_file_to_image(game->mlx,
			"./textures/Floor.xpm", &tw, &th);
	game->wall_txtr = mlx_xpm_file_to_image(game->mlx,
			"./textures/Wall.xpm", &tw, &th);
}

static int	init_game(t_game *game)
{
	game->w = ft_strlen(game->map[0]);
	if (game->w * T_SIZE > 1920 || (game->h * T_SIZE) > 1080)
	{
		ft_fdprintf(2, "Error\nMap is too long/wide.\n");
		return (1);
	}
	game->move_cnt = 0;
	game->collect_cnt = count_collect_cnt(game->map);
	game->mlx = mlx_init();
	if (!game->mlx || init_window(game) == 1)
	{
		ft_fdprintf(2, "Error\nCouldn't load the game! HOW?\n");
		return (1);
	}
	init_textures(game);
	if (!game->player_txtr || !game->collectible_txtr || !game->exit_txtr
		|| !game->floor_txtr || !game->wall_txtr)
	{
		ft_fdprintf(2, "Error\nCouldn't load textures, Oof.\n");
		closewin(game);
		return (1);
	}
	return (0);
}

static void	put_img(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->player_txtr,
		game->px * T_SIZE, game->py * T_SIZE);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_fdprintf(2, "Error\nNot enough or Too many args\n");
		return (1);
	}
	game.map = create_map(argv, ft_strlen(argv[1]), &game);
	if (!game.map)
		return (1);
	find_player(game.map, &game.px, &game.py);
	if (init_game(&game) == 1)
	{
		freemap(game.map);
		return (1);
	}
	mlx_key_hook(game.win, key_handler, &game);
	mlx_hook(game.win, 17, 0, closewin, &game);
	mlx_loop_hook(game.mlx, renderframe, &game);
	render(&game);
	put_img(&game);
	mlx_loop(game.mlx);
	freemap(game.map);
	return (0);
}
