/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_in_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 16:22:42 by ttampio           #+#    #+#             */
/*   Updated: 2020/08/29 17:57:07 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_in_arr(char **arr, char *str)
{
	size_t i;

	if (!arr || !arr[0] || !str)
		return (0);
	i = -1;
	while (arr[++i])
		if (ft_strcmp(arr[i], str) == 0)
			return (1);
	return (0);
}
