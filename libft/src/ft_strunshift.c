/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strunshift.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 21:53:48 by ttampio           #+#    #+#             */
/*   Updated: 2020/07/03 22:38:09 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strunshift(char ***strarr_ptr, char *newstr)
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
	i = 0;
	new_strarr[i] = newstr;
	while ((*strarr_ptr)[++i - 1])
		new_strarr[i] = (*strarr_ptr)[i - 1];
	new_strarr[i] = NULL;
	free(*strarr_ptr);
	*strarr_ptr = new_strarr;
	return (i + 1);
}
