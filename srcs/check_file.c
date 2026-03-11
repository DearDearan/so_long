/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 23:46:38 by lifranco          #+#    #+#             */
/*   Updated: 2026/03/11 17:53:29 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_invalid_char(char **map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[x])
	{
		while (map[x][y])
		{
			if (map[x][y] != '0' && map[x][y] != '1' && map[x][y] != 'P'
				&& map[x][y] != 'E' && map[x][y] != 'C')
				return (1);
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}

static int	check_player(char **map)
{
	int	x;
	int	y;
	int	player;

	player = 0;
	y = 0;
	x = 0;
	while (map[x])
	{
		while (map[x][y])
		{
			if (map[x][y] == 'P')
				player++;
			y++;
		}
		y = 0;
		x++;
	}
	return (player);
}

static int	check_walls(char **map, int height)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[0][x])
	{
		if (map[0][x] != '1' || map[height - 1][x] != '1')
		{
			ft_fdprintf(2, "Error\nInvalid Horizontal Walls. Oopsie :3\n");
			return (1);
		}
		x++;
	}
	while (map[y])
	{
		if (map[y][0] != '1' || map[y][ft_strlen(map[y]) - 1] != '1')
		{
			ft_fdprintf(2, "Error\nInvalid Vertical Walls. Oopsie :3\n");
			return (1);
		}
		y++;
	}
	return (0);
}

int	check_file_length(char **map)
{
	int		i;
	size_t	line_len;

	i = 0;
	line_len = ft_strlen(map[0]) - 1;
	while (map[i])
	{
		if ((ft_strlen(map[i]) - 1) != line_len)
		{
			ft_fdprintf(2, "Error\nInvalid Map. Check your line lengths.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_valid(char **map, int height)
{
	int	fill_res;

	if (check_player(map) != 1)
	{
		ft_fdprintf(2, "Error\nToo Many Players / No Players Online.\n");
		return (1);
	}
	if (check_invalid_char(map) == 1)
	{
		ft_fdprintf(2, "Error\nCharacter Not Recognized. Missinput much?\n");
		return (1);
	}
	fill_res = check_fill(map, height);
	if (fill_res == 2 || check_walls(map, height) == 1 
		|| check_exit(map) == 1)
		return (1);
	if (fill_res == 1 || !count_collect_cnt(map))
	{
		if(fill_res == 1)
			ft_fdprintf(2, "Error\nNo access to Exit or Bags, DOOR STUCK\n");
		else
		 	ft_fdprintf(2, "Error\nNo Collectible, Place's already clean.\n");
		return (1);
	}
	return (0);
}
