/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 11:01:03 by lifranco          #+#    #+#             */
/*   Updated: 2025/11/10 14:36:34 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (s == 0)
		return (write(fd, "(null)", 6));
	while (s[i])
	{
		ft_putlchar_fd(s[i], fd);
		i++;
	}
	return (i);
}
