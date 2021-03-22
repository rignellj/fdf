/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dinsert_before.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:42:28 by jrignell          #+#    #+#             */
/*   Updated: 2020/12/23 14:44:54 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dinsert_before(t_dlist **node, t_dlist *new)
{
	if (!*node)
	{
		*node = new;
		new->prev = NULL;
		new->next = NULL;
	}
	else if (*node && !(*node)->prev)
	{
		new->next = *node;
		new->prev = NULL;
		(*node)->prev = new;
	}
	else
	{
		new->next = *node;
		new->prev = (*node)->prev;
		(*node)->prev->next = new;
		(*node)->prev = new;
	}
}
