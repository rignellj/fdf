/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraynew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:39:34 by jrignell          #+#    #+#             */
/*   Updated: 2020/12/16 13:39:36 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arraynew(size_t size)
{
	char	**array;
	size_t	i;

	i = 0;
	if (!(array = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (i < size)
		array[i++] = 0;
	array[i] = 0;
	return (array);
}
