/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptpsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 12:43:12 by jrignell          #+#    #+#             */
/*   Updated: 2020/11/13 13:06:10 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Does the same as ft_strsub() but uses char * as delimiter
*/

char	*ft_ptpsub(char *start, char *end)
{
	size_t	len;
	size_t	i;
	char	*sub;

	len = (size_t)(end - start);
	i = 0;
	if (!(sub = (char *)ft_memalloc(len + 1)))
		return (NULL);
	while (i < len && start[i])
	{
		sub[i] = start[i];
		i++;
	}
	sub[len] = '\0';
	return (sub);
}
