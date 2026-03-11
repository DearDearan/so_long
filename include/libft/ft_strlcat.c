/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:49:00 by lifranco          #+#    #+#             */
/*   Updated: 2025/10/28 12:21:20 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	j = 0;
	if (!n)
		return (ft_strlen(src));
	res = ft_strlen(dest);
	while (dest[i] && i < n)
		i++;
	if (i == n)
		return (n + ft_strlen(src));
	while ((j + i) < n - 1 && src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	if (res < n)
		return (res + ft_strlen(src));
	else
		return (n + ft_strlen(src));
}
