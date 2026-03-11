/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:30:52 by lifranco          #+#    #+#             */
/*   Updated: 2025/10/19 21:54:50 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	j = 0;
	i = 0;
	if (s2[i] == 0)
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		while ((s1[i + j] == s2[j]) && s1[i + j] && i + j < n)
			j++;
		if (s2[j] == '\0')
			return ((char *)&s1[i]);
		i++;
		j = 0;
	}
	return (NULL);
}
