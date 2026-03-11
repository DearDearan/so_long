/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 09:10:55 by lifranco          #+#    #+#             */
/*   Updated: 2026/03/11 17:54:08 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	keypressed(int key, t_game *game)
{
	if (key == XK_w && game->map[game->py - 1][game->px] != '1')
		handle(key, game);
	if (key == XK_s && game->map[game->py + 1][game->px] != '1')
		handle(key, game);
	if (key == XK_a && game->map[game->py][game->px - 1] != '1')
		handle(key, game);
	if (key == XK_d && game->map[game->py][game->px + 1] != '1')
		handle(key, game);
	ft_fdprintf(1, "Moves done : %d\n", game->move_cnt);
}

int	key_handler(int key, t_game *game)
{
	if (key == XK_Escape)
		closewin(game);
	if (key == XK_w || key == XK_a || key == XK_s || key == XK_d)
		keypressed(key, game);
	return (0);
}

int	gamewin(t_game *game)
{
	ft_fdprintf(1,
		"You cleaned the evidence, are you happy with yourself?\n");
	ft_fdprintf(1, "You made %d moves to clean the place.\n", game->move_cnt + 1);
	closewin(game);
	return (0);
}
