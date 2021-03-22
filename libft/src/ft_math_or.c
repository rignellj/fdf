/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_or.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:44:13 by jrignell          #+#    #+#             */
/*   Updated: 2021/01/14 17:44:43 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_math_or(int int_1, int int_2)
{
	char	*result;

	result = ft_itoa(int_1 || int_2);
	return (result);
}
