/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 23:32:08 by lifranco          #+#    #+#             */
/*   Updated: 2026/03/11 15:02:24 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

static void	remove_nl(char *str)
{
	size_t	len;

	if (!str)
		return ;
	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
}

static char	**fill_map(int file, int height)
{
	int		i;
	char	**map;

	i = 0;
	map = ft_calloc(height + 1, sizeof(char *));
	while (map && i < height)
	{
		map[i] = get_next_line(file);
		if (!map[i])
		{
			freemap(map);
			return (NULL);
		}
		remove_nl(map[i]);
		i++;
	}
	if (!map || height == 0 || check_file_length(map) == 1
		|| check_valid(map, height) == 1)
	{
		if (!map)
			ft_fdprintf(2, "Error\nMalloc Error");
		freemap(map);
		return (NULL);
	}
	return (map);
}

static int	open_file(char **argv)
{
	int	file;

	file = open(argv[1], O_RDONLY);
	if (file < 0)
		ft_fdprintf(2, "Error\nCannot Open File or File does not exist.\n");
	return (file);
}

static int	count_lines(int file)
{
	int		i;
	char	*map_line;

	i = 0;
	map_line = get_next_line(file);
	if (!map_line)
	{
		ft_fdprintf(2, "Error\nYou just sent NOTHING. Don't. STOP IT.\n");
		return (0);
	}
	else if (ft_strlen(map_line) * T_SIZE > 1920)
	{
		ft_fdprintf(2, "Error\nMap is too long/wide.\n");
		free(map_line);
		return (0);
	}
	while (map_line != NULL)
	{
		i++;
		free(map_line);
		map_line = get_next_line(file);
	}
	return (i);
}

char	**create_map(char **argv, int argv_len, t_game *game)
{
	int		file;
	char	**map;

	if (check_args(argv, argv_len) == 1)
		return (NULL);
	file = open_file(argv);
	if (file < 0)
		return (NULL);
	game->h = count_lines(file);
	gnl_drain(file);
	close(file);
	file = open_file(argv);
	if (file < 0 || !game->h)
		return (NULL);
	map = fill_map(file, game->h);
	if (!map)
	{
		freemap(map);
		close(file);
		return (NULL);
	}
	gnl_drain(file);
	close(file);
	return (map);
}
