/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:37:36 by lifranco          #+#    #+#             */
/*   Updated: 2025/11/10 14:33:32 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlnbr_fd(int n, int fd)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		if (write(fd, "-2147483648", 11) == -1)
			return (-1);
		return (11);
	}
	if (n < 0)
	{
		n *= -1;
		i += ft_putlchar_fd('-', fd);
	}
	if (n >= 10)
	{
		i += ft_putlnbr_fd(n / 10, fd);
		i += ft_putlchar_fd((n % 10) + '0', fd);
	}
	else
		i += ft_putlchar_fd(n + '0', fd);
	return (i);
}
