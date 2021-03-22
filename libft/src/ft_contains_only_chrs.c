/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_only_chrs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 19:08:17 by ttampio           #+#    #+#             */
/*   Updated: 2021/01/04 20:01:38 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  If all characters in string <str> are <chrs> return true.
**	If <allow_empty> is true, empty string returns true also, false otherwise.
*/

int	ft_contains_only_chrs(char *str, char *chrs, int allow_empty)
{
	int	i;

	if (*str == '\0' && !allow_empty)
		return (0);
	while (*str)
	{
		i = 0;
		while (chrs[i])
			if (*str == chrs[i])
				break ;
			else
				i++;
		if (chrs[i] == '\0')
			return (0);
		str++;
	}
	return (1);
}
