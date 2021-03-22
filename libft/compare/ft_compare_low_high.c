/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare_low_high.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:09:44 by jrignell          #+#    #+#             */
/*   Updated: 2020/12/16 14:01:49 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_compare_low_high(void *s1, void *s2)
{
	char	*ptr1;
	char	*ptr2;
	size_t	i;

	i = 0;
	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	while (ptr1[i] == ptr2[i] && ptr1[i] && ptr2[i])
		i++;
	return ((unsigned char)ptr1[i] - (unsigned char)ptr2[i]);
}
