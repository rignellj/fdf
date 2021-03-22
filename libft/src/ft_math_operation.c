/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:42:14 by jrignell          #+#    #+#             */
/*   Updated: 2021/02/05 14:14:08 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_math_operation(const void *first, const void *second, size_t size,
		char *(*op)(int, int))
{
	int		int_1;
	int		int_2;

	if (size == sizeof(char))
	{
		int_1 = ft_atoi((char *)first);
		int_2 = ft_atoi((char *)second);
	}
	else
	{
		int_1 = (int)first;
		int_2 = (int)second;
	}
	return (op(int_1, int_2));
}
