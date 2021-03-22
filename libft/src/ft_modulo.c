/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modulo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:57:23 by jrignell          #+#    #+#             */
/*   Updated: 2021/01/18 16:02:27 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_modulo(int int_1, int int_2)
{
	char	*result;

	if (int_2 == 0)
		return (NULL);
	result = ft_itoa(int_1 % int_2);
	return (result);
}
