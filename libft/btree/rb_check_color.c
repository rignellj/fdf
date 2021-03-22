/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_check_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 11:11:25 by jrignell          #+#    #+#             */
/*   Updated: 2021/02/05 14:17:41 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	rb_check_color(t_rb_btree **root_node, t_rb_btree *root,
		int (*cmpf)(void *, void *))
{
	if (*root_node == root)
		return ;
	if (root->color == RB_RED && root->parent->color == RB_RED)
		rb_correct_tree(root_node, root, cmpf);
	rb_check_color(root_node, root->parent, cmpf);
}
