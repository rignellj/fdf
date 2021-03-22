/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 15:43:56 by jrignell          #+#    #+#             */
/*   Updated: 2020/08/12 11:05:31 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

static void	btree_insert_help(t_btree *root, void *item,
			int (*cmpf)(void *, void *))
{
	if (cmpf(item, root->item) < 0)
	{
		if (!root->left)
			root->left = btree_create_node(item);
		else
			btree_insert_help(root->left, item, cmpf);
	}
	else
	{
		if (!root->right)
			root->right = btree_create_node(item);
		else
			btree_insert_help(root->right, item, cmpf);
	}
}

void		btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	if (!*root)
		*root = btree_create_node(item);
	else
		btree_insert_help(*root, item, cmpf);
}
