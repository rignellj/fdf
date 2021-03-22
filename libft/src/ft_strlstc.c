/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlstc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 13:38:38 by ttampio           #+#    #+#             */
/*   Updated: 2020/08/18 17:06:38 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  Checks whether last char of <str> is <c>.
*/

int	ft_strlstc(char *str, int c)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	if (i == 0)
		return (0);
	else if (str[i - 1] == c)
		return (1);
	return (0);
}
