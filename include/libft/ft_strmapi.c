/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 10:55:57 by lifranco          #+#    #+#             */
/*   Updated: 2025/10/30 18:50:47 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*strres;

	i = 0;
	if (!s || !f)
		return (NULL);
	strres = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (strres == NULL)
		return (NULL);
	while (i < ft_strlen(s))
	{
		strres[i] = f(i, s[i]);
		i++;
	}
	strres[i] = '\0';
	return (strres);
}
