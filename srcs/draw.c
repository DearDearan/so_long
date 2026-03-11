/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 00:43:41 by lifranco          #+#    #+#             */
/*   Updated: 2026/03/10 16:11:37 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_pixel(char *addr, int *info, int x, int y)
{
	return (*(int *)(addr + (y * info[1] + x * (info[0] / 8))));
}

void	draw_sprite(t_game *game, void *txtr, int dx, int dy)
{
	char			*src;
	int				info[3];
	int				pos[2];
	unsigned int	color;

	src = mlx_get_data_addr(txtr, &info[0], &info[1], &info[2]);
	pos[1] = 0;
	while (pos[1] < T_SIZE)
	{
		pos[0] = 0;
		while (pos[0] < T_SIZE)
		{
			color = get_pixel(src, info, pos[0], pos[1]);
			if (color != 0xFF000000)
				my_mlx_pixel_put(game, dx + pos[0], dy + pos[1], color);
			pos[0]++;
		}
		pos[1]++;
	}
}
