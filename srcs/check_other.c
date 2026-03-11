/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:58:42 by lifranco          #+#    #+#             */
/*   Updated: 2026/03/11 15:01:01 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_exit(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	if (!map || !*map)
		return (1);
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count == 0 || count > 1)
	{
		ft_fdprintf(2, "Error\nNO EXIT/MORE THAN 1 EXIT. YOU CANT ESCAPE.\n");
		return (1);
	}
	return (0);
}
