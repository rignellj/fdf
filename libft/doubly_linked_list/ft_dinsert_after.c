/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dinsert_after.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:12:27 by jrignell          #+#    #+#             */
/*   Updated: 2020/12/23 14:31:42 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dinsert_after(t_dlist **node, t_dlist *new)
{
	if (!*node)
	{
		*node = new;
		new->prev = NULL;
		new->next = NULL;
	}
	else if (*node && !(*node)->next)
	{
		new->prev = (*node);
		new->next = NULL;
		(*node)->next = new;
	}
	else
	{
		new->prev = *node;
		new->next = (*node)->next;
		(*node)->next->prev = new;
		(*node)->next = new;
	}
}
