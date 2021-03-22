/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiterif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 13:00:44 by jrignell          #+#    #+#             */
/*   Updated: 2020/12/21 16:53:16 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

int		ft_dlstiterif(t_dlist *lst, int (*f)(t_dlist *elem))
{
	t_dlist	*ptr;

	ptr = lst;
	while (ptr)
	{
		if (!f(ptr))
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
