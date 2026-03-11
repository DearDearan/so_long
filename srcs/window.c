/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 00:10:41 by lifranco          #+#    #+#             */
/*   Updated: 2026/03/11 17:44:31 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= game->winimg.img.imgw)
		return ;
	else if (y < 0 || y >= game->winimg.img.imgh)
		return ;
	dst = game->addr + (y * game->llen + x * (game->bits / 8));
	*(unsigned int *)dst = color;
}

void	destroy_textures(t_game *game)
{
	if (game->player_txtr)
		mlx_destroy_image(game->mlx, game->player_txtr);
	if (game->collectible_txtr)
		mlx_destroy_image(game->mlx, game->collectible_txtr);
	if (game->exit_txtr)
		mlx_destroy_image(game->mlx, game->exit_txtr);
	if (game->floor_txtr)
		mlx_destroy_image(game->mlx, game->floor_txtr);
	if (game->wall_txtr)
		mlx_destroy_image(game->mlx, game->wall_txtr);
}

int	closewin(t_game *game)
{
	if (!game->mlx)
		exit (1);
	destroy_textures(game);
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	freemap(game->map);
	exit(0);
}

int	init_window(t_game *game)
{
	game->img = mlx_new_image(game->mlx, game->w * T_SIZE, game->h * T_SIZE);
	if (!game->img)
		return (1);
	game->addr = mlx_get_data_addr(game->img, &game->bits,
			&game->llen, &game->endian);
	if (!game->addr)
		return (1);	
	game->win = mlx_new_window(game->mlx, game->w * T_SIZE, game->h * T_SIZE,
			"So long, and thanks for the corpses!");
	if (!game->win)
		return (1);
	game->winimg.img.imgh = game->h * T_SIZE;
	game->winimg.img.imgw = game->w * T_SIZE;
	return (0);
}
