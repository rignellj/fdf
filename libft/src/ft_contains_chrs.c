/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_chrs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 10:46:18 by ttampio           #+#    #+#             */
/*   Updated: 2020/08/09 19:38:22 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  If any character in string <chrs> is found from string <str>, return true.
*/

int	ft_contains_chrs(char *str, char *chrs)
{
	int	i;

	while (*str)
	{
		i = 0;
		while (chrs[i])
			if (*str == chrs[i++])
				return (1);
		str++;
	}
	return (0);
}
