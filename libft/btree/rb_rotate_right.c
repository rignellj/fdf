/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_rotate_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 11:43:07 by jrignell          #+#    #+#             */
/*   Updated: 2021/02/05 14:23:22 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	rb_rotate_right(t_rb_btree **root_node, t_rb_btree *root,
		int (*cmpf)(void *, void *))
{
	t_rb_btree	*left_child;

	left_child = root->left;
	root->left = left_child->right;
	left_child->parent = root->parent;
	if (left_child->parent)
	{
		if (cmpf(left_child->item, left_child->parent->item) < 0)
			left_child->parent->left = left_child;
		else
			left_child->parent->right = left_child;
	}
	else
		*root_node = left_child;
	left_child->right = root;
	root->parent = left_child;
}
