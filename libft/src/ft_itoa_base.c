/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 18:51:07 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/03 19:30:13 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init(char **s, int upper)
{
	if (upper == 1)
		*s = "0123456789ABCDEF";
	else
		*s = "0123456789abcdef";
}

static void	init2(int *i, long long value, int base, unsigned long long *n)
{
	unsigned long long	temp;

	if (value < 0 && base == 10)
		*i = 2;
	else
		*i = 1;
	if (value < 0)
		*n = -value;
	else
		*n = value;
	temp = *n;
	while (temp > 0)
	{
		temp /= base;
		(*i)++;
	}
}

char	*ft_itoa_base(long long value, int base, int upper)
{
	char				*s;
	char				*res;
	int					i;
	unsigned long long	n;

	init(&s, upper);
	init2(&i, value, base, &n);
	res = ft_strnew(i);
	if (!res)
		return (NULL);
	while (n)
	{
		res[--i] = s[n % base];
		n = n / base;
	}
	if (value == 0)
		res[0] = '0';
	else if (value < 0 && base == 10)
		res[0] = '-';
	return (res);
}
