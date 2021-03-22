/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_preorder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:15:26 by jrignell          #+#    #+#             */
/*   Updated: 2021/02/05 14:15:30 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	btree_apply_preorder(t_btree *root, void (*applyf)(void *))
{
	if (!root || !applyf)
		return ;
	applyf(root->item);
	if (root->left)
		btree_apply_preorder(root->left, applyf);
	if (root->right)
		btree_apply_preorder(root->right, applyf);
}
