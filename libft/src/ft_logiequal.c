/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logiequal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:39:56 by jrignell          #+#    #+#             */
/*   Updated: 2021/01/14 17:40:13 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_logiequal(int int_1, int int_2)
{
	char	*result;

	result = ft_itoa(int_1 != int_2);
	return (result);
}
