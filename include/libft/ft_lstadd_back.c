/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:47:34 by lifranco          #+#    #+#             */
/*   Updated: 2026/01/20 15:27:14 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newnode)
{
	t_list	*lastnode;

	if (!lst || !newnode)
		return ;
	if (*lst == NULL)
	{
		*lst = newnode;
		return ;
	}
	lastnode = *lst;
	while (lastnode->next)
		lastnode = lastnode->next;
	lastnode->next = newnode;
}
