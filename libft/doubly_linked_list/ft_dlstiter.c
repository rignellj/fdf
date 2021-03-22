/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:20:02 by jrignell          #+#    #+#             */
/*   Updated: 2020/12/21 16:52:34 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dlstiter(t_dlist *lst, void (*f)(t_dlist *elem))
{
	t_dlist	*ptr;

	ptr = lst;
	while (ptr)
	{
		f(ptr);
		ptr = ptr->next;
	}
}
