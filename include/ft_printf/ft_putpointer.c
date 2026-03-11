/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:17:07 by lifranco          #+#    #+#             */
/*   Updated: 2026/02/15 04:07:21 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *p, unsigned int write_zero, int fd)
{
	unsigned long	ptr;
	int				i;
	char			*hex;

	hex = "0123456789abcdef";
	i = 0;
	if (p == NULL)
		return (write(fd, "(nil)", 5));
	ptr = (unsigned long)p;
	if (write_zero == 0)
	{
		if (write(fd, "0x", 2) == -1)
			return (-1);
		i += 2;
	}
	if (ptr >= 16)
		i += ft_putpointer((void *)(ptr / 16), 1, fd);
	if (write(fd, &hex[ptr % 16], 1) == -1)
		return (-1);
	i += 1;
	return (i);
}
