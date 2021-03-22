/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_double_rotation_right.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 12:17:14 by jrignell          #+#    #+#             */
/*   Updated: 2021/02/05 14:17:31 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	rb_double_rotation_right(t_rb_btree **root_node, t_rb_btree *root,
		int (*cmpf)(void *, void *))
{
	rb_rotate_left(root_node, root->left, cmpf);
	rb_rotate_right(root_node, root->left, cmpf);
}
