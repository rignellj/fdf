/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_or_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:37:58 by jrignell          #+#    #+#             */
/*   Updated: 2021/01/18 15:42:42 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_or_add(t_list **head, const void *data, size_t size)
{
	t_list	*new;

	if (*head)
	{
		if (!(new = ft_lstnew(data, size)))
			return (NULL);
		ft_lstaddend(head, new);
	}
	else
	{
		*head = ft_lstnew(data, size);
	}
	return (*head);
}
