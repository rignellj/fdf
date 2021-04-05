/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:38:25 by ttampio           #+#    #+#             */
/*   Updated: 2021/04/03 12:27:42 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	node = (t_list *)ft_memalloc(sizeof(t_list));
	if (!node)
		return (NULL);
	if (!content)
	{
		node->content_size = 0;
		node->content = NULL;
	}
	else
	{
		node->content = (t_list *)ft_memalloc(content_size);
		if (!node->content)
			return (NULL);
		ft_memcpy(node->content, content, content_size);
		node->content_size = content_size;
	}
	node->next = NULL;
	return (node);
}
