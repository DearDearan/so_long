/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbrhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 01:44:59 by lifranco          #+#    #+#             */
/*   Updated: 2026/02/15 04:14:18 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlnbrhex(unsigned int n, unsigned int what_case, int fd)
{
	char	*base_low;
	char	*base_upp;
	int		i;

	i = 0;
	base_low = "0123456789abcdef";
	base_upp = "0123456789ABCDEF";
	if (n >= 16)
		i += ft_putlnbrhex(n / 16, what_case, fd);
	if (what_case == 0)
	{
		if (write(fd, &base_low[n % 16], 1) == -1)
			return (-1);
		i += 1;
	}
	else if (what_case == 1)
	{
		if (write(fd, &base_upp[n % 16], 1) == -1)
			return (-1);
		i += 1;
	}
	return (i);
}
