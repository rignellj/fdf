/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_of_ten.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:11:21 by ttampio           #+#    #+#             */
/*   Updated: 2019/12/16 10:53:31 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned long long	ft_power_of_ten(int n)
{
	unsigned long long	res;

	res = 1;
	while (n--)
		res = res * 10;
	return (res);
}
