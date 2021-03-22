/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:24:46 by jrignell          #+#    #+#             */
/*   Updated: 2020/12/21 16:53:22 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"
#include <stdlib.h>

t_dlist		*ft_dlstmap(t_dlist *lst, t_dlist *(*f)(t_dlist *elem))
{
	t_dlist	*current;
	t_dlist	*first;

	if (!lst)
		return (NULL);
	first = f(lst);
	current = first;
	while (lst->next)
	{
		lst = lst->next;
		current->next = f(lst);
		if (!(current->next))
		{
			free(current->next);
			return (NULL);
		}
		current = current->next;
	}
	return (first);
}
