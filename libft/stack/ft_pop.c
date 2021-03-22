/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:46:55 by jrignell          #+#    #+#             */
/*   Updated: 2021/02/02 12:06:56 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	*ft_pop(t_list **head)
{
	t_list	*del_node;
	void	*ret;

	if (ft_isempty(*head))
		return (NULL);
	del_node = *head;
	*head = (*head)->next;
	ret = del_node->content;
	ft_memdel((void **)&del_node);
	return (ret);
}
