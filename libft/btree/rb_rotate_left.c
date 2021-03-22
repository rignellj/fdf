/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_rotate_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 12:07:23 by jrignell          #+#    #+#             */
/*   Updated: 2021/02/05 14:15:39 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	rb_rotate_left(t_rb_btree **root_node, t_rb_btree *root,
		int (*cmpf)(void *, void *))
{
	t_rb_btree	*right_child;

	right_child = root->right;
	root->right = right_child->left;
	right_child->parent = root->parent;
	if (right_child->parent)
	{
		if (cmpf(right_child->item, right_child->parent->item) < 0)
			right_child->parent->left = right_child;
		else
			right_child->parent->right = right_child;
	}
	else
		*root_node = right_child;
	right_child->left = root;
	root->parent = right_child;
}
