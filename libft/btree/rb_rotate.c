/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:28:28 by jrignell          #+#    #+#             */
/*   Updated: 2021/02/05 14:21:27 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

static void	rb_right_rotate(t_rb_btree **root_node, t_rb_btree *root,
			int (*cmpf)(void *, void *))
{
	rb_rotate_right(root_node, root->parent->parent, cmpf);
	root->color = RB_RED;
	root->parent->color = RB_BLACK;
	if (root->parent->right)
		root->parent->right->color = RB_RED;
}

static void	rb_left_rotate(t_rb_btree **root_node, t_rb_btree *root,
			int (*cmpf)(void *, void *))
{
	rb_rotate_left(root_node, root->parent->parent, cmpf);
	root->color = RB_RED;
	root->parent->color = RB_BLACK;
	if (root->parent->left)
		root->parent->left->color = RB_RED;
}

static void	rb_right_left(t_rb_btree **root_node, t_rb_btree *root,
			int (*cmpf)(void *, void *))
{
	rb_double_rotation_left(root_node, root->parent->parent, cmpf);
	root->color = RB_BLACK;
	if (root->left)
		root->left->color = RB_RED;
	if (root->right)
		root->right->color = RB_RED;
}

static void	rb_left_right(t_rb_btree **root_node, t_rb_btree *root,
			int (*cmpf)(void *, void *))
{
	rb_double_rotation_right(root_node, root->parent->parent, cmpf);
	root->color = RB_BLACK;
	if (root->left)
		root->left->color = RB_RED;
	if (root->right)
		root->right->color = RB_RED;
}

void		rb_rotate(t_rb_btree **root_node, t_rb_btree *root,
			int (*cmpf)(void *, void *))
{
	if (rb_which_child(root, cmpf) == LEFT_CHILD)
	{
		if (rb_which_child(root->parent, cmpf) == LEFT_CHILD)
			rb_right_rotate(root_node, root, cmpf);
		else if (rb_which_child(root->parent, cmpf) == RIGHT_CHILD)
			rb_right_left(root_node, root, cmpf);
	}
	else if (rb_which_child(root, cmpf) == RIGHT_CHILD)
	{
		if (rb_which_child(root->parent, cmpf) == RIGHT_CHILD)
			rb_left_rotate(root_node, root, cmpf);
		else if (rb_which_child(root->parent, cmpf) == LEFT_CHILD)
			rb_left_right(root_node, root, cmpf);
	}
}
