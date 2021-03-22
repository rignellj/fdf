/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 19:33:04 by jrignell          #+#    #+#             */
/*   Updated: 2020/08/16 11:00:24 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_list	*queue_push(t_list **head, const void *data, size_t size)
{
	t_list	*new_node;
	t_list	*tmp;

	if (!(new_node = queue_new(data, size)))
		return (NULL);
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	return (*head);
}
