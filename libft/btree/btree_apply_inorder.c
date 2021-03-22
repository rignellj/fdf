/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_inorder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 15:12:35 by jrignell          #+#    #+#             */
/*   Updated: 2020/08/15 16:36:56 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	btree_apply_inorder(t_btree *root, void (*applyf)(void *))
{
	if (!root || !applyf)
		return ;
	if (root->left)
		btree_apply_inorder(root->left, applyf);
	applyf(root->item);
	if (root->right)
		btree_apply_inorder(root->right, applyf);
}
