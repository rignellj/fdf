/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstget_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 11:41:01 by jrignell          #+#    #+#             */
/*   Updated: 2020/12/21 16:50:05 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

t_dlist		*ft_dlstget_first(t_dlist *current)
{
	t_dlist	*first;

	first = current;
	while (first)
	{
		if (!first->prev)
			break ;
		first = first->prev;
	}
	return (first);
}
