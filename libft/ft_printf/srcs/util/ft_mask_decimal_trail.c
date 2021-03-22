/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mask_decimal_trail.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:08:13 by ttampio           #+#    #+#             */
/*   Updated: 2019/12/12 16:10:44 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long double	ft_mask_decimal_trail(long double db_value, int prec)
{
	long double rounded;
	int			dec_jumped;

	rounded = db_value;
	rounded -= (1.0 / ft_power_of_ten(prec + 2));
	dec_jumped = ((long)(rounded * ft_power_of_ten(prec + 3) / 10) % 10) == 9;
	return (dec_jumped ? db_value : rounded);
}
