/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:58:57 by ttampio           #+#    #+#             */
/*   Updated: 2021/04/03 18:25:30 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_fill_str(int n, char *s)
{
	size_t	i;

	i = 0;
	if (n / 10)
		i = ft_fill_str(n / 10, s);
	else if (n < 0)
	{
		if (n < 0)
			s[i++] = '-';
	}
	if (n < 0)
		n = -n;
	s[i++] = n % 10 + '0';
	s[i] = '\0';
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;

	if (n == -2147483648)
		s = ft_strdup("-2147483648");
	else
	{
		s = ft_strnew(12);
		if (!s)
			return (NULL);
		ft_fill_str(n, s);
	}
	return (s);
}
