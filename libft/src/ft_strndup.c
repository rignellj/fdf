/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:20:25 by ttampio           #+#    #+#             */
/*   Updated: 2020/08/15 17:22:20 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dup;

	dup = (char*)malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (dup);
	ft_memcpy(dup, s1, n);
	dup[n] = '\0';
	return (dup);
}
