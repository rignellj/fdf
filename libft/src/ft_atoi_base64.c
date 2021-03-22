/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base64.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:27:20 by jrignell          #+#    #+#             */
/*   Updated: 2021/02/05 14:14:26 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	right_value(char c, int base)
{
	if (base <= 36)
	{
		if (c >= '0' && c <= '9')
			return (c - '0');
		else if (c >= 'A' && c <= 'Z')
			return (c - 'A' + 10);
		else
			return (c - 'a' + 10);
	}
	else
	{
		if (c >= '0' && c <= '9')
			return (c - '0');
		else if (c >= 'a' && c <= 'z')
			return (c - 'a' + 10);
		else if (c >= 'A' && c <= 'Z')
			return (c - 'A' + 36);
		else if (c == '@')
			return (c - '@' + 62);
		else
			return (c - '_' + 63);
	}
}

int			ft_atoi_base64(const char *num, int base)
{
	size_t	i;
	size_t	res;
	int		sign;

	sign = (*num == '-' && base == 10) ? -1 : 1;
	i = 0;
	res = 0;
	while (num[i])
	{
		if (!ft_belongs_to_base(num[i], base))
			return (sign * res);
		res = res * base + right_value(num[i], base);
		i++;
	}
	return (sign * res);
}
