/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:24:33 by lifranco          #+#    #+#             */
/*   Updated: 2025/10/30 19:12:46 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	getinstr(char *str, int n, int i)
{
	if (n < 0)
		n *= -1;
	while (n >= 10 && i > 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	str[i] = n + '0';
	return (*str);
}

static size_t	intlen(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (10);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n >= 10)
	{
		n /= 10;
		count ++;
	}
	return (count + 1);
}

char	*ft_itoa(int n)
{
	int		i;
	int		ntemp;
	char	*alpha;

	ntemp = n;
	i = intlen(n) - 1;
	if (n == -2147483648)
	{
		alpha = ft_strdup("-2147483648");
		return (alpha);
	}
	alpha = ft_calloc(intlen(n) + 1, sizeof(char));
	if (!alpha)
		return (NULL);
	getinstr(alpha, n, i);
	if (ntemp < 0)
		alpha[0] = '-';
	alpha[intlen(ntemp)] = 0;
	return (alpha);
}
