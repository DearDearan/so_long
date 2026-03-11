/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:45:00 by lifranco          #+#    #+#             */
/*   Updated: 2025/10/30 19:07:39 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	unsigned char	*cdest;
	unsigned char	*csrc;
	void			*str;	

	cdest = dest;
	csrc = src;
	if (dest > src)
	{
		while (n--)
			cdest[n] = csrc[n];
		return (cdest);
	}
	str = ft_memcpy(dest, src, n);
	return (str);
}
