/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 19:18:55 by ttampio           #+#    #+#             */
/*   Updated: 2020/11/13 14:15:55 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  removes character from index <i> in string. Returns 0 on success,
**  -1 otherwise if <str> isn't valid, -2 for malloc error.
*/

int	ft_strremchr(char **str, size_t i)
{
	size_t	len;
	char	*new_str;

	if (!str || !*str)
		return (-1);
	len = ft_strlen(*str);
	if (i >= len || len == 0)
		return (-1);
	if (i == 0)
		new_str = ft_strsub(*str, 1, len - 1);
	else if (i == len - 1)
		new_str = ft_strsub(*str, 0, len - 1);
	else
	{
		(*str)[i] = '\0';
		new_str = ft_strjoin(*str, &(*str)[i + 1]);
	}
	free(*str);
	*str = new_str;
	return (new_str ? 0 : -2);
}
