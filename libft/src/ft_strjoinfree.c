/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:29:14 by ttampio           #+#    #+#             */
/*   Updated: 2021/04/03 13:26:27 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, t_strjointype frtype)
{
	char	*new_s;
	size_t	s1_lngth;
	size_t	s2_lngth;

	if (!s1 || !s2)
		return (NULL);
	s1_lngth = ft_strlen(s1);
	s2_lngth = ft_strlen(s2);
	new_s = (char *)malloc(s1_lngth + s2_lngth + 1);
	if (!(new_s))
		return (new_s);
	ft_strcpy(new_s, s1);
	ft_strcpy(new_s + s1_lngth, s2);
	if (frtype == FREE_LEFT || frtype == FREE_BOTH)
		free(s1);
	if (frtype == FREE_RIGHT || frtype == FREE_BOTH)
		free(s2);
	return (new_s);
}
