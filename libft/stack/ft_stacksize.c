/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:10:21 by jrignell          #+#    #+#             */
/*   Updated: 2021/01/14 11:26:29 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		ft_stacksize(t_list **head, int exceed)
{
	t_list	*current;
	int		size;

	size = 0;
	current = *head;
	exceed = (int)ft_abs(exceed);
	while (current)
	{
		if (exceed && exceed == size)
			return (-exceed);
		size++;
		current = current->next;
	}
	return (size);
}
