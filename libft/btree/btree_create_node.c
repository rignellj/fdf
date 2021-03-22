/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 14:50:01 by jrignell          #+#    #+#             */
/*   Updated: 2020/08/12 10:36:39 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*new_node;

	if (!(new_node = (t_btree *)ft_memalloc(sizeof(t_btree))))
		return (NULL);
	new_node->item = item;
	return (new_node);
}
