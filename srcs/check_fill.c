/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 03:46:40 by lifranco          #+#    #+#             */
/*   Updated: 2026/03/10 14:58:52 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill(char **map, int x, int y, int height)
{
	if (!map || x < 0 || (size_t)x >= ft_strlen(map[0]) - 1 || map[y][x] == '1'
		|| map[y][x] == 'V' || y >= height || y < 0)
		return ;
	map[y][x] = 'V';
	fill(map, x + 1, y, height);
	fill(map, x - 1, y, height);
	fill(map, x, y + 1, height);
	fill(map, x, y - 1, height);
}

void	find_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map && map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*y = i;
				*x = j;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static char	**copy_map(char **map, int height)
{
	int		i;
	char	**new;

	i = 0;
	new = ft_calloc(height + 1, sizeof(char *));
	while (new && map[i])
	{
		new[i] = ft_strdup(map[i]);
		if (!new[i])
		{
			ft_fdprintf(2, "Error\nMalloc Error.\n");
			freemap(new);
			return (NULL);
		}
		i++;
	}
	return (new);
}

int	check_fill(char **map, int height)
{
	int		x;
	int		y;
	char	**tmp;

	tmp = copy_map(map, height);
	find_player(tmp, &x, &y);
	fill(tmp, x, y, height);
	y = -1;
	while (tmp && tmp[++y])
	{
		x = 0;
		while (tmp[y][x])
		{
			if (tmp[y][x] == 'C' || tmp[y][x] == 'E')
			{
				freemap(tmp);
				return (1);
			}
			x++;
		}
	}
	if (!tmp)
		return (2);
	freemap(tmp);
	return (0);
}
