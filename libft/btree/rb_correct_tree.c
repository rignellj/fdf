/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_correct_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:56:44 by jrignell          #+#    #+#             */
/*   Updated: 2021/02/05 14:16:47 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	rb_correct_tree(t_rb_btree **root_node, t_rb_btree *root,
		int (*cmpf)(void *, void *))
{
	if (rb_which_child(root->parent, cmpf) == LEFT_CHILD)
	{
		if (root->parent->parent->right == NULL ||
			root->parent->parent->right->color == RB_BLACK)
			return (rb_rotate(root_node, root, cmpf));
		else if (root->parent->parent->right != NULL)
			root->parent->parent->right->color = RB_BLACK;
		root->parent->parent->color = RB_RED;
		root->parent->color = RB_BLACK;
	}
	else if (rb_which_child(root->parent, cmpf) == RIGHT_CHILD)
	{
		if (root->parent->parent->left == NULL ||
			root->parent->parent->left->color == RB_BLACK)
			return (rb_rotate(root_node, root, cmpf));
		else if (root->parent->parent->left != NULL)
			root->parent->parent->left->color = RB_BLACK;
		root->parent->parent->color = RB_RED;
		root->parent->color = RB_BLACK;
	}
}
