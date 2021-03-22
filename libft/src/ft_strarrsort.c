/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 18:00:36 by ttampio           #+#    #+#             */
/*   Updated: 2020/08/29 18:06:55 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strarrsort(char **arr)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	if (!arr || !arr[0])
		return ;
	i = 0;
	while (arr[i])
	{
		j = i;
		while (arr[++j])
			if (ft_strcmp(arr[i], arr[j]) > 0)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		i++;
	}
}
