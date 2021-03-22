/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:51:09 by ttampio           #+#    #+#             */
/*   Updated: 2020/08/15 17:19:46 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	s_lngth;
	char	chr;

	chr = (char)c;
	s_lngth = ft_strlen(s);
	i = s_lngth;
	while (1)
	{
		if (s[i] == chr)
			return ((char*)&s[i]);
		else if (i == 0)
			return (NULL);
		i--;
	}
	return (NULL);
}
