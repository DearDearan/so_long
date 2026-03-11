/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 11:44:19 by lifranco          #+#    #+#             */
/*   Updated: 2026/02/15 04:15:36 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# define FT_PRINTF_H

int		ft_fdprintf(int fd, const char *str, ...);
int		ft_putlunbr(unsigned int n, int fd);
int		ft_putlnbr_fd(int n, int fd);
int		ft_putlchar_fd(char c, int fd);
int		ft_putlstr_fd(char *s, int fd);
int		ft_putpointer(void *p, unsigned int write_zero, int fd);
int		ft_putlnbrhex(unsigned int n, unsigned int what_case, int fd);

#endif
