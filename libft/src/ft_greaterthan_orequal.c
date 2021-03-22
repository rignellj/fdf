/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_greaterthan_orequal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:36:09 by jrignell          #+#    #+#             */
/*   Updated: 2021/01/14 17:36:35 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_greaterthan_orequal(int int_1, int int_2)
{
	char	*result;

	result = ft_itoa(int_1 >= int_2);
	return (result);
}
