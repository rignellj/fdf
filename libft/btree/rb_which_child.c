/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_which_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 14:53:32 by jrignell          #+#    #+#             */
/*   Updated: 2020/08/13 12:36:54 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

int		rb_which_child(t_rb_btree *root, int (*cmpf)(void *, void *))
{
	if (root->parent == NULL)
		return (0);
	else if (cmpf(root->item, root->parent->item) < 0)
		return (LEFT_CHILD);
	return (RIGHT_CHILD);
}
