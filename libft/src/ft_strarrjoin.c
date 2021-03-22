/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 21:27:35 by ttampio           #+#    #+#             */
/*   Updated: 2021/01/21 12:11:39 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_arr(char **merged_arr, char **src_arr, size_t *i)
{
	while (*src_arr)
	{
		merged_arr[(*i)++] = *src_arr;
		src_arr++;
	}
}

/*
**	merges 2 arrays together.
**	NOTE: Also frees arrays given as parameters!
*/

char		**ft_strarrjoin(char **arr1, char **arr2)
{
	size_t	len1;
	size_t	len2;
	char	**merged_arr;
	size_t	i;

	len1 = arr1 ? ft_strarrlen(arr1) : 0;
	len2 = arr2 ? ft_strarrlen(arr2) : 0;
	merged_arr = (char**)malloc(sizeof(char*) * (len1 + len2 + 1));
	if (!merged_arr)
		return (NULL);
	i = 0;
	if (arr1 && *arr1)
		copy_arr(merged_arr, arr1, &i);
	arr1 ? free(arr1) : 0;
	if (arr2 && *arr2)
		copy_arr(merged_arr, arr2, &i);
	arr2 ? free(arr2) : 0;
	merged_arr[i] = NULL;
	return (merged_arr);
}
