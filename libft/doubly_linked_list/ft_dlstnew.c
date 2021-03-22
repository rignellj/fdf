/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 12:54:43 by jrignell          #+#    #+#             */
/*   Updated: 2021/01/14 09:32:24 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

t_dlist		*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist	*new;

	if (!(new = (t_dlist *)ft_memalloc(sizeof(t_dlist))))
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(new->content = ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
