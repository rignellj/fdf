/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_print_inorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 12:56:38 by jrignell          #+#    #+#             */
/*   Updated: 2020/08/15 19:03:43 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	rb_print_inorder(t_rb_btree *node, void (*print)(void *, int))
{
	if (node == NULL)
		return ;
	if (node->left)
		rb_print_inorder(node->left, print);
	if (node && node->item)
		print(node->item, node->color);
	if (node->right)
		rb_print_inorder(node->right, print);
}
