/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:52:14 by lifranco          #+#    #+#             */
/*   Updated: 2025/10/30 18:37:58 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	char	*str;
	size_t	k;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	j = ft_strlen(s1) - 1 ;
	while (is_set(set, s1[i]))
		i++;
	while (is_set(set, s1[j]) && j > i)
		j--;
	if (i > j)
		return (ft_calloc(1, 1));
	str = ft_calloc((j - i) + 2, sizeof(char));
	if (str == NULL)
		return (NULL);
	k = j + 1;
	j = 0;
	while (i < k)
		str[j++] = s1[i++];
	return (str);
}
