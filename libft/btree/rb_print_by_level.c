/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_print_by_level.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 20:04:16 by jrignell          #+#    #+#             */
/*   Updated: 2021/02/05 14:22:07 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

static void	add_to_queue(t_rb_btree *node, t_list **list, t_list *tmp_list)
{
	if (!node)
		return ;
	if (node->left)
		tmp_list = tmp_list ? queue_push(&tmp_list, node->left,
		sizeof(t_rb_btree)) : queue_new(node->left, sizeof(t_rb_btree));
	if (node->right)
		tmp_list = tmp_list ? queue_push(&tmp_list,
		node->right, sizeof(t_rb_btree)) :
		queue_new(node->right, sizeof(t_rb_btree));
	if (!*list)
		*list = queue_new(node, sizeof(t_rb_btree));
	else
		*list = queue_push(list, node, sizeof(t_rb_btree));
	if (ft_isempty(tmp_list))
		return ;
	add_to_queue((t_rb_btree *)ft_pop(&tmp_list), list, tmp_list);
}

void		rb_print_by_level(t_rb_btree *node, t_list *list,
			void (*print)(void *, int))
{
	t_rb_btree	*current;
	int			level;
	int			nodes;

	if (!node)
		return ;
	if (!list)
		list = queue_new(node, sizeof(t_rb_btree));
	add_to_queue((t_rb_btree *)ft_pop(&list), &list, NULL);
	level = 0;
	while (!ft_isempty(list))
	{
		nodes = ft_power(2, level);
		ft_printf("At level %d, there are these nodes: \n", level);
		while (nodes-- && !ft_isempty(list))
		{
			current = (t_rb_btree *)ft_pop(&list);
			print(current->item, current->color);
		}
		level++;
	}
}
