/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 11:46:55 by lifranco          #+#    #+#             */
/*   Updated: 2026/02/15 04:15:09 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	display_value(const char c, va_list *params, int *error, int fd)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putlchar_fd(va_arg(*params, int), fd);
	else if (c == 's')
		count = ft_putlstr_fd(va_arg(*params, char *), fd);
	else if (c == 'p')
		count = ft_putpointer(va_arg(*params, void *), 0, fd);
	else if (c == 'd')
		count = ft_putlnbr_fd(va_arg(*params, int), fd);
	else if (c == 'i')
		count = ft_putlnbr_fd(va_arg(*params, int), fd);
	else if (c == 'u')
		count = ft_putlunbr(va_arg(*params, unsigned int), fd);
	else if (c == 'x')
		count = ft_putlnbrhex(va_arg(*params, unsigned int), 0, fd);
	else if (c == 'X')
		count = ft_putlnbrhex(va_arg(*params, unsigned int), 1, fd);
	else if (c == '%')
		count = ft_putlchar_fd('%', fd);
	if (count == -1)
		*error = 1;
	return (count);
}

int	ft_fdprintf(int fd, const char *str, ...)
{
	va_list	params;
	int		count;
	int		i;
	int		error;

	error = 0;
	count = 0;
	i = 0;
	if (!str)
		return (-1);
	va_start(params, str);
	while (str[i] != 0)
	{
		if (str[i] == '%' && str[i + 1])
			count += display_value(str[++i], &params, &error, fd);
		else if (write(fd, &str[i], 1) == -1)
			return (-1);
		else
			count++;
		i++;
	}
	va_end(params);
	if (!error)
		return (count);
	return (-1);
}
