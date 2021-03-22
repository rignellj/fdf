/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:57:24 by jrignell          #+#    #+#             */
/*   Updated: 2020/08/10 15:17:14 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
********************************************************************************
** Nodes will be traversed using infix (inorder) algorithm                    **
********************************************************************************
*/

#include "btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	if (root->left && cmpf(data_ref, root->left->item) <= 0)
	{
		if (cmpf(data_ref, root->left->item) == 0)
			return (root->left->item);
		return (btree_search_item(root->left, data_ref, cmpf));
	}
	else if (root->item && cmpf(data_ref, root->item) == 0)
		return (root->item);
	else if (root->right && cmpf(data_ref, root->right->item) >= 0)
	{
		if (cmpf(data_ref, root->right->item) == 0)
			return (root->right->item);
		return (btree_search_item(root->right, data_ref, cmpf));
	}
	else
		return (NULL);
}
