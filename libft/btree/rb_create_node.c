/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 10:55:25 by jrignell          #+#    #+#             */
/*   Updated: 2020/08/15 17:37:44 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

t_rb_btree	*rb_create_node(void const *item, size_t content_size)
{
	t_rb_btree	*new_node;

	if (!(new_node = (t_rb_btree *)ft_memalloc(sizeof(t_rb_btree))))
		return (NULL);
	if (!item)
	{
		new_node->item = NULL;
		new_node->color = RB_BLACK;
	}
	else
	{
		if (!(new_node->item = ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(new_node->item, item, content_size);
		new_node->color = RB_RED;
	}
	new_node->right = NULL;
	new_node->left = NULL;
	return (new_node);
}
