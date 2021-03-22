/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_postorder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 15:14:30 by jrignell          #+#    #+#             */
/*   Updated: 2020/08/09 15:31:53 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	btree_apply_postorder(t_btree *root, void (*applyf)(void *))
{
	if (!root || !applyf)
		return ;
	if (root->left)
		btree_apply_postorder(root->left, applyf);
	if (root->right)
		btree_apply_postorder(root->right, applyf);
	applyf(root->item);
}
