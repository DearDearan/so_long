/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 23:27:22 by lifranco          #+#    #+#             */
/*   Updated: 2026/03/11 17:44:28 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle(int key, t_game *game)
{
	mlx_destroy_image(game->mlx, game->player_txtr);
	game->player_txtr = NULL;
	if (key == XK_w)
	{
		moveup(game);
		put_player_txtr(key, game);
	}
	if (key == XK_s)
	{
		movedown(game);
		put_player_txtr(key, game);
	}
	if (key == XK_a)
	{
		moveleft(game);
		put_player_txtr(key, game);
	}
	if (key == XK_d)
	{
		moveright(game);
		put_player_txtr(key, game);
	}
}

void	moveup(t_game *game)
{
	if (game->map[game->py][game->px] != 'E')
		game->map[game->py][game->px] = '0';
	game->py--;
	if (game->map[game->py][game->px] == 'C')
		game->collect_cnt--;
	if (game->collect_cnt == 0 && game->map[game->py][game->px] == 'E')
	{
		gamewin(game);
		return ;
	}
	if (game->map[game->py][game->px] != 'E')
		game->map[game->py][game->px] = 'P';
	game->move_cnt += 1;
}

void	movedown(t_game *game)
{
	if (game->map[game->py][game->px] != 'E')
		game->map[game->py][game->px] = '0';
	game->py++;
	if (game->map[game->py][game->px] == 'C')
		game->collect_cnt--;
	if (game->collect_cnt == 0 && game->map[game->py][game->px] == 'E')
	{
		gamewin(game);
		return ;
	}
	if (game->map[game->py][game->px] != 'E')
		game->map[game->py][game->px] = 'P';
	game->move_cnt += 1;
}

void	moveleft(t_game *game)
{
	if (game->map[game->py][game->px] != 'E')
		game->map[game->py][game->px] = '0';
	game->px--;
	if (game->map[game->py][game->px] == 'C')
		game->collect_cnt--;
	if (game->collect_cnt == 0 && game->map[game->py][game->px] == 'E')
	{
		gamewin(game);
		return ;
	}
	if (game->map[game->py][game->px] != 'E')
		game->map[game->py][game->px] = 'P';
	game->move_cnt += 1;
}

void	moveright(t_game *game)
{
	if (game->map[game->py][game->px] != 'E')
		game->map[game->py][game->px] = '0';
	game->px++;
	if (game->map[game->py][game->px] == 'C')
		game->collect_cnt--;
	if (game->collect_cnt == 0 && game->map[game->py][game->px] == 'E')
	{
		gamewin(game);
		return ;
	}
	if (game->map[game->py][game->px] != 'E')
		game->map[game->py][game->px] = 'P';
	game->move_cnt += 1;
}
