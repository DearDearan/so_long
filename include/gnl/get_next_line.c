/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:05:20 by lifranco          #+#    #+#             */
/*   Updated: 2026/02/09 07:00:20 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*join(char *buff, int fd)
{
	char	*tmp_buff;
	char	*old_buff;
	int		bytesread;

	tmp_buff = malloc(BUFFER_SIZE + 1);
	if (!tmp_buff)
		return (NULL);
	while (ft_gnlstrchr(buff, '\n') == NULL)
	{
		bytesread = read(fd, tmp_buff, BUFFER_SIZE);
		if (bytesread < 0)
		{
			free(tmp_buff);
			free(buff);
			return (NULL);
		}
		if (!bytesread)
			break ;
		tmp_buff[bytesread] = 0;
		old_buff = buff;
		buff = ft_gnlstrjoin(buff, tmp_buff);
		free(old_buff);
	}
	free(tmp_buff);
	return (buff);
}

char	*read_and_join(char *buff, int fd)
{
	if (buff == NULL)
	{
		buff = malloc(1);
		if (!buff)
			return (NULL);
		buff[0] = 0;
	}
	buff = join(buff, fd);
	if (!buff || !*buff)
	{
		free(buff);
		return (NULL);
	}
	return (buff);
}

char	*get_ret_line(char const *buff)
{
	char	*new_buff;
	int		i;
	int		j;

	i = 0;
	if (!buff || !*buff)
		return (NULL);
	while (buff[i] != '\n' && buff[i])
		i++;
	if (i == ft_gnlstrlen(buff))
		new_buff = malloc((i + 1) * sizeof(char));
	else
		new_buff = malloc((i + 2) * sizeof(char));
	if (new_buff == NULL)
		return (NULL);
	j = 0;
	while (j++ < i)
		new_buff[j - 1] = buff[j - 1];
	if (buff[i] == '\n')
	{
		new_buff[i] = '\n';
		i++;
	}
	new_buff[i] = 0;
	return (new_buff);
}

char	*clean_stash(char *buff)
{
	int		i;
	char	*newstash;

	i = 0;
	if (!buff || !*buff)
		return (NULL);
	while (buff[i] != '\n' && buff[i])
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	newstash = ft_gnlsubstr(buff, i + 1, ft_gnlstrlen(buff) - (i + 1));
	free(buff);
	if (!newstash || !*newstash)
	{
		free(newstash);
		return (NULL);
	}
	return (newstash);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_join(stash, fd);
	if (!stash || !*stash)
		return (NULL);
	ret = get_ret_line(stash);
	stash = clean_stash(stash);
	return (ret);
}
