/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lessthan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:30:42 by jrignell          #+#    #+#             */
/*   Updated: 2021/01/14 17:31:00 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lessthan(int int_1, int int_2)
{
	char	*result;

	result = ft_itoa(int_1 < int_2);
	return (result);
}
