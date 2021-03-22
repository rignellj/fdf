/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremnchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 13:12:52 by ttampio           #+#    #+#             */
/*   Updated: 2020/08/18 17:11:14 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  Removes characters from the end of the string.
*/

char	*ft_strremnchr(char **str, size_t n)
{
	char	*trimmed_str;
	size_t	strlen;

	strlen = ft_strlen(*str);
	if (n > strlen)
		n = strlen;
	trimmed_str = ft_strsub(*str, 0, strlen - n);
	if (!trimmed_str)
		return (NULL);
	free(*str);
	*str = trimmed_str;
	return (trimmed_str);
}
