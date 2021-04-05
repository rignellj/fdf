/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:06:52 by ttampio           #+#    #+#             */
/*   Updated: 2021/04/03 13:59:35 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * (size + 1));
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s1, size);
	dup[size] = '\0';
	return (dup);
}
