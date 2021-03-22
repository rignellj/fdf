/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_greaterthan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:32:53 by jrignell          #+#    #+#             */
/*   Updated: 2021/01/14 17:33:11 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_greaterthan(int int_1, int int_2)
{
	char	*result;

	result = ft_itoa(int_1 > int_2);
	return (result);
}
