/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 15:22:27 by jrignell          #+#    #+#             */
/*   Updated: 2020/12/21 16:51:53 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dlstappend(t_dlist **alst, t_dlist *new)
{
	t_dlist	*current;

	if (!alst)
		return ;
	new->next = NULL;
	if ((*alst) == NULL)
	{
		new->prev = NULL;
		(*alst) = new;
	}
	else
	{
		current = (*alst);
		while (current->next)
			current = current->next;
		current->next = new;
		new->prev = current;
	}
}
