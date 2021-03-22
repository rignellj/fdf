/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_chrs_n.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 10:46:18 by ttampio           #+#    #+#             */
/*   Updated: 2020/11/08 18:34:08 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  If any character in string <chrs> is found from string <str>, return true.
**  Checks only <n>-number of chars from string.
*/

int	ft_contains_chrs_n(char *str, char *chrs, size_t n)
{
	int		i;
	size_t	j;

	j = 0;
	while (str[j] && j <= n)
	{
		i = 0;
		while (chrs[i])
			if (str[j] == chrs[i++])
				return (1);
		j++;
	}
	return (0);
}
