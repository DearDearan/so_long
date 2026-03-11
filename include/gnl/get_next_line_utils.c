/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 05:58:33 by lifranco          #+#    #+#             */
/*   Updated: 2026/02/09 06:59:43 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_gnlstrlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_gnlstrjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;
	int		size;
	size_t	j;

	size = 0;
	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (malloc(sizeof(char) * sizeof(char)));
	size = (ft_gnlstrlen(s1) + ft_gnlstrlen(s2));
	if (size == 0)
		return (malloc(sizeof(char) * sizeof(char)));
	str = malloc((size + 1) * sizeof(char));
	if (str == 0)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

char	*ft_gnlstrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == 0)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_gnlsubstr(char const *s, unsigned int start, int len)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (malloc(1));
	if (start > (unsigned int) ft_gnlstrlen(s))
		return (malloc(1));
	if (len > ft_gnlstrlen(s + start))
		len = ft_gnlstrlen(s + start);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
