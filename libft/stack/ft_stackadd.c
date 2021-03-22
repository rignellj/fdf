/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:00:27 by jrignell          #+#    #+#             */
/*   Updated: 2021/01/18 15:05:35 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_list	*ft_stackadd(t_list **head, const void *data, size_t size)
{
	if (*head)
		*head = ft_stackpush(head, data, size);
	else
		*head = ft_stacknew(data, size);
	return (*head);
}
