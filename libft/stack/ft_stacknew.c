/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:02:14 by jrignell          #+#    #+#             */
/*   Updated: 2020/12/20 15:20:37 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_list	*ft_stacknew(const void *data, size_t content_size)
{
	t_list	*new_node;

	if (!(new_node = ft_lstnew(data, content_size)))
		return (NULL);
	return (new_node);
}
