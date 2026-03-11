/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:55:06 by lifranco          #+#    #+#             */
/*   Updated: 2026/02/09 06:56:48 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H 
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*read_and_join(char *buff, int fd);
char	*get_next_line(int fd);
char	*clean_stash(char *buff);
char	*get_ret_line(char const *buff);

int		ft_gnlstrlen(const char *str);
char	*ft_gnlstrjoin(char const *s1, char const *s2);
char	*ft_gnlstrchr(const char *s, int c);
char	*ft_gnlsubstr(char const *s, unsigned int start, int len);

#endif
