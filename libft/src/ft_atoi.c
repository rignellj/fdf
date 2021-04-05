/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:48:23 by ttampio           #+#    #+#             */
/*   Updated: 2021/04/03 13:31:16 by jrignell         ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	res;
	size_t	sign;

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
