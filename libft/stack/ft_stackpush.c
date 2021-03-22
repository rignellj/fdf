/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:20:51 by jrignell          #+#    #+#             */
/*   Updated: 2020/12/20 14:41:19 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_list	*ft_stackpush(t_list **head, const void *data, size_t size)
{
	t_list	*new_node;

	if (!(new_node = ft_stacknew(data, size)))
		return (NULL);
	new_node->next = *head;
	*head = new_node;
	return (*head);
}
