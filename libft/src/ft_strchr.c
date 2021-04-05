/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:06:03 by ttampio           #+#    #+#             */
/*   Updated: 2021/04/03 18:37:57 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	s_lngth;
	char	chr;

	chr = (char)c;
	s_lngth = ft_strlen(s);
	i = 0;
	while (i <= s_lngth)
	{
		if (s[i] == chr)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	return (NULL);
}
