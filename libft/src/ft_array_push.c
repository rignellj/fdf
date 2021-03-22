/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:39:03 by jrignell          #+#    #+#             */
/*   Updated: 2020/12/16 13:39:07 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_array_push(char **array, char *str, int index)
{
	char	**des;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (array && array[i])
		i++;
	if (!(des = (char**)malloc(sizeof(char*) * (i + 2))))
		return (NULL);
	i = 0;
	while (array && array[j])
	{
		if (i == index)
			des[i++] = ft_strdup(str);
		else
			des[i++] = ft_strdup(array[j++]);
	}
	if (index == -1 || index >= i)
		des[i++] = ft_strdup(str);
	des[i] = 0;
	return (des);
}
