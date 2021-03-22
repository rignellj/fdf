/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 10:45:35 by ttampio           #+#    #+#             */
/*   Updated: 2019/12/09 10:45:42 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_define_start(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || \
			str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	return (i);
}

long long	ft_atoll(const char *str)
{
	size_t		i;
	long long	res;
	size_t		sign;

	res = 0;
	sign = 1;
	i = ft_define_start(str);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (res * sign);
		res = res * 10 + str[i++] - '0';
	}
	return (sign * res);
}
