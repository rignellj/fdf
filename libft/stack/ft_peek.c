/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_peek.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:30:21 by jrignell          #+#    #+#             */
/*   Updated: 2020/08/15 19:43:41 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	*ft_peek(t_list *head)
{
	if (ft_isempty(head))
		return (NULL);
	return (head->content);
}
