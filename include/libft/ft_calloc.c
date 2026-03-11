/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:46:10 by lifranco          #+#    #+#             */
/*   Updated: 2025/10/30 19:48:48 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t element_count, size_t element_size)
{
	size_t			i;
	unsigned char	*mall;
	size_t			t_max;

	t_max = (size_t)-1;
	i = 0;
	if (element_count && (t_max / element_count) < element_size)
		return (NULL);
	mall = malloc(element_count * element_size);
	if (mall == NULL)
		return (NULL);
	while (i < element_count * element_size)
	{
		mall[i] = 0;
		i++;
	}
	return (mall);
}
