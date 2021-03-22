/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstget_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 11:41:38 by jrignell          #+#    #+#             */
/*   Updated: 2021/02/03 22:30:22 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

t_dlist		*ft_dlstget_last(t_dlist *current)
{
	t_dlist	*last;

	last = current;
	while (last)
	{
		if (!last->next)
			break ;
		last = last->next;
	}
	return (last);
}
