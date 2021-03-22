/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 10:21:16 by jrignell          #+#    #+#             */
/*   Updated: 2021/02/05 14:21:37 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

static void	rb_insert_help(t_rb_btree **root_node, t_rb_btree *root,
			void *item, int (*cmpf)(void *, void *))
{
	if (cmpf(item, root->item) < 0)
	{
		if (!root->left)
		{
			root->left = rb_create_node(item, sizeof(item));
			root->left->parent = root;
			rb_check_color(root_node, root->left, cmpf);
		}
		else
			rb_insert_help(root_node, root->left, item, cmpf);
	}
	else
	{
		if (!root->right)
		{
			root->right = rb_create_node(item, sizeof(item));
			root->right->parent = root;
			rb_check_color(root_node, root->right, cmpf);
		}
		else
			rb_insert_help(root_node, root->right, item, cmpf);
	}
}

void		rb_insert(t_rb_btree **root, void *item,
			int (*cmpf)(void *, void *))
{
	if (!*root)
	{
		(*root) = rb_create_node(item, sizeof(item));
		(*root)->parent = NULL;
	}
	else
		rb_insert_help(root, *root, item, cmpf);
	(*root)->color = RB_BLACK;
}
