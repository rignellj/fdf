/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:45:03 by ttampio           #+#    #+#             */
/*   Updated: 2021/04/03 18:37:30 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	s1_lngth;
	size_t	s2_lngth;

	if (!s1 || !s2)
		return (NULL);
	s1_lngth = ft_strlen(s1);
	s2_lngth = ft_strlen(s2);
	new_s = (char *)malloc(s1_lngth + s2_lngth + 1);
	if (!new_s)
		return (new_s);
	ft_strcpy(new_s, s1);
	ft_strcpy(new_s + s1_lngth, s2);
	return (new_s);
}
