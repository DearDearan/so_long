/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 00:10:41 by lifranco          #+#    #+#             */
/*   Updated: 2026/03/04 13:58:46 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	destroy_textures(game);
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	freemap(game->map);
	exit(0);
}
