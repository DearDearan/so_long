/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlunbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:35:55 by lifranco          #+#    #+#             */
/*   Updated: 2026/02/15 04:13:08 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlunbr(unsigned int n, int fd)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_putlunbr(n / 10, fd);
		i += ft_putlchar_fd((n % 10) + '0', fd);
	}
	else
		i += ft_putlchar_fd(n + '0', fd);
	return (i);
}
