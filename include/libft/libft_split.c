/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnantet <dnantet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:25:16 by dnantet           #+#    #+#             */
/*   Updated: 2026/01/08 21:03:21 by dnantet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char sep)
{
	int	i;
	int	wcount;
	int	wfound;

	i = 0;
	wcount = 0;
	wfound = 0;
	while (str[i])
	{
		if (str[i] != sep && wfound == 0)
		{
			wfound = 1;
			wcount++;
		}
		else if (str[i] == sep)
			wfound = 0;
		i++;
	}
	return (wcount);
}

static const char	*find_word(char const *str, const char sep, int ref)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == sep)
		i++;
	while (ref > 0)
	{
		while (str[i] && str[i] != sep)
			i++;
		while (str[i] && str[i] == sep)
			i++;
		ref--;
	}
	return (&str[i]);
}

static void	fill_word(char *slot, char const *word, int const size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		slot[i] = word[i];
		i++;
	}
	slot[i] = '\0';
}

static void	*free_all(char **tab, int wcount)
{
	int	i;

	i = 0;
	while (i < wcount)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	char	*word;
	char	**tab;

	if (!(s || c))
		return (NULL);
	i = 0;
	tab = ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!tab)
		return (NULL);
	while (i < count_words(s, c))
	{
		j = 0;
		word = (char *) find_word(s, c, i);
		while (word[j] && word[j] != c)
			j++;
		tab[i] = ft_calloc((j + 1), sizeof(char));
		if (!tab[i])
			return (free_all(tab, i));
		fill_word(tab[i], word, j);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
