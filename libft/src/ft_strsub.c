/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:19:37 by ttampio           #+#    #+#             */
/*   Updated: 2021/04/03 14:00:28 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;

	sub_s = ft_strnew(len);
	if (!(sub_s))
		return (NULL);
	i = 0;
	while (len)
	{
		sub_s[i++] = s[start++];
		len--;
	}
	sub_s[i] = '\0';
	return (sub_s);
}
