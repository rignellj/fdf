/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 21:13:55 by ttampio           #+#    #+#             */
/*   Updated: 2020/07/31 18:15:33 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strpush(char ***strarr_ptr, char *newstr)
{
	char	**new_strarr;
	size_t	i;

	if (!newstr)
		return (-1);
	if (!*strarr_ptr)
	{
		if (!(*strarr_ptr = (char**)malloc(sizeof(char*))))
			return (-1);
		(*strarr_ptr)[0] = NULL;
	}
	i = 0;
	while ((*strarr_ptr)[i])
		i++;
	new_strarr = (char**)malloc(sizeof(char*) * (i + 2));
	if (!new_strarr)
		return (-1);
	i = -1;
	while ((*strarr_ptr)[++i])
		new_strarr[i] = (*strarr_ptr)[i];
	new_strarr[i] = newstr;
	new_strarr[i + 1] = NULL;
	free(*strarr_ptr);
	*strarr_ptr = new_strarr;
	return (i + 1);
}
