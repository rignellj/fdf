/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strskp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:49:18 by ttampio           #+#    #+#             */
/*   Updated: 2021/01/16 14:35:48 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Jumps over quoted part of a string. Returns 1 if quote is properly closed,
**	0 otherwise.
*/

int	ft_strskp(char *str, char skipchr, int skipescpd, size_t *org_i)
{
	size_t	*i;

	i = org_i;
	*i += 1;
	while (str[*i])
	{
		if (str[*i] == '\\' && skipescpd && str[*i + 1] != '\0')
			*i += 2;
		if (str[*i] == skipchr)
		{
			*i += 1;
			return (1);
		}
		*i += 1;
	}
	return (0);
}
