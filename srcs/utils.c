/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:50:32 by lifranco          #+#    #+#             */
/*   Updated: 2026/03/04 13:50:39 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_args(char **argv, int argv_len)
{
	if (!argv[1] || !*argv[1])
	{
		ft_fdprintf(2, "Error\nNo Map. This does NOT work. Stop it.");
		return (1);
	}
	if (argv_len < 4 || ft_strncmp(argv[1] + argv_len - 4, ".ber", 4) != 0)
	{
		ft_fdprintf(2,
			"Error\nInvalid Extension. It must end in '.ber' dood.");
		return (1);
	}
	return (0);
}

void	gnl_drain(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

void	freemap(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	render(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			draw_sprite(game, game->floor_txtr, x * T_SIZE, y * T_SIZE);
			if (game->map[y][x] == '1')
				draw_sprite(game, game->wall_txtr, x * T_SIZE, y * T_SIZE);
			else if (game->map[y][x] == 'C')
				draw_sprite(game,
					game->collectible_txtr, x * T_SIZE, y * T_SIZE);
			else if (game->map[y][x] == 'E')
				draw_sprite(game, game->exit_txtr, x * T_SIZE, y * T_SIZE);
			x++;
		}
		y++;
	}
}

void	put_player_txtr(int key, t_game *game)
{
	int	th;
	int	tw;

	th = T_SIZE;
	tw = T_SIZE;
	if (key == XK_w)
		game->player_txtr = mlx_xpm_file_to_image(game->mlx,
				"./textures/Player4.xpm", &tw, &th);
	if (key == XK_s)
		game->player_txtr = mlx_xpm_file_to_image(game->mlx,
				"./textures/Player3.xpm", &tw, &th);
	if (key == XK_a)
		game->player_txtr = mlx_xpm_file_to_image(game->mlx,
				"./textures/Player1.xpm", &tw, &th);
	if (key == XK_d)
		game->player_txtr = mlx_xpm_file_to_image(game->mlx,
				"./textures/Player2.xpm", &tw, &th);
}
