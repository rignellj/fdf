/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrescpd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:27:55 by ttampio           #+#    #+#             */
/*   Updated: 2021/01/21 12:11:28 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Checks if character is escaped.
*/

int	ft_chrescpd(size_t i, char esc_c, char *str)
{
	int		is_escaped;

	if (i == 0)
		return (0);
	i--;
	is_escaped = 0;
	while (str[i] != 0)
	{
		if (str[i] != esc_c)
			return (is_escaped);
		else
			is_escaped = !is_escaped;
		i--;
	}
	return (str[i] == esc_c ? !is_escaped : is_escaped);
}
