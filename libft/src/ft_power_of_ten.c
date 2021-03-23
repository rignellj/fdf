/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_of_ten.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:11:21 by ttampio           #+#    #+#             */
/*   Updated: 2021/03/22 18:35:22 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_power_of_ten(int n)
{
	unsigned long long	res;

	res = 1;
	while (n--)
		res = res * 10;
	return (res);
}
