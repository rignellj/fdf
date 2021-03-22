/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_division.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:54:45 by jrignell          #+#    #+#             */
/*   Updated: 2021/01/18 15:59:57 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_division(int int_1, int int_2)
{
	char	*result;

	if (int_2 == 0)
		return (NULL);
	result = ft_itoa(int_1 / int_2);
	return (result);
}
