/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 09:13:51 by jrignell          #+#    #+#             */
/*   Updated: 2020/08/11 10:02:26 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

int			btree_level_count(t_btree *root)
{
	int		left;
	int		right;

	left = 0;
	right = 0;
	if (root)
	{
		left = btree_level_count(root->left);
		right = btree_level_count(root->right);
		return (left > right ? left + 1 : right + 1);
	}
	else
		return (0);
}
