/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 17:45:30 by ttampio           #+#    #+#             */
/*   Updated: 2019/12/05 17:45:50 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

static int	ft_fill_str(long long n, char *s)
{
	size_t i;

	i = 0;
	if (n / 10)
		i = ft_fill_str(n / 10, s);
	else if (n < 0)
		s[i++] = '-';
	if (n < 0)
		n = -n;
	s[i++] = n % 10 + '0';
	s[i] = '\0';
	return (i);
}

char		*ft_lltoa(long long n)
{
	char *s;

	if (n == -9223372036854775807 - 1)
		s = ft_strdup("-9223372036854775808");
	else
	{
		if (!(s = ft_strnew(20)))
			return (NULL);
		ft_fill_str(n, s);
	}
	return (s);
}
