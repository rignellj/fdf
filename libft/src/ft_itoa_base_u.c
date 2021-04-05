/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:56:26 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/03 18:35:03 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init(char **s, int upper, int *i)
{
	if (upper == 1)
		*s = "0123456789ABCDEF";
	else
		*s = "0123456789abcdef";
	*i = 1;
}

char	*ft_itoa_base_u(unsigned long long int value, int base, int upper)
{
	char				*s;
	char				*res;
	int					i;
	unsigned long long	temp;

	init(&s, upper, &i);
	temp = value;
	while (temp > 0)
	{
		temp /= base;
		i++;
	}
	res = ft_strnew(i);
	if (!res)
		return (NULL);
	if (!value)
		*res = '0';
	while (value)
	{
		res[--i] = s[value % base];
		value = value / base;
	}
	return (res);
}
