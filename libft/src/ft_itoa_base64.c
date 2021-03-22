/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base64.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:01:14 by jrignell          #+#    #+#             */
/*   Updated: 2021/01/21 13:34:35 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	define_str(char **s, int base, int upper)
{
	if (base >= 2 && base <= 36)
	{
		if (upper)
			*s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		else
			*s = "0123456789abcdefghijklmnopqrstuvwxyz";
	}
	else
		*s = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ@_";
}

char		*ft_itoa_base64(long long value, int base, int upper)
{
	char				*s;
	char				*res;
	unsigned long long	tmp;
	unsigned long long	num;
	size_t				i;

	define_str(&s, base, upper);
	i = (value < 0 && base == 10) ? 2 : 1;
	num = ft_abs(value);
	tmp = num;
	while ((tmp /= base) > 0)
		i++;
	if (!(res = ft_strnew(i)))
		return (NULL);
	while (num)
	{
		res[--i] = s[num % base];
		num = num / base;
	}
	if (value == 0)
		res[0] = '0';
	else if (value < 0 && base == 10)
		res[0] = '-';
	return (res);
}
