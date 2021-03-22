/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrescpd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:31:02 by ttampio           #+#    #+#             */
/*   Updated: 2021/02/05 14:14:16 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	<str>:		string where check is performed
**	<i>:		index of the character that is checked whether it is escaped
**	<escp_chr>:	character that is considered to be an escape character
*/

int	ft_strchrescpd(char *str, size_t i, char escp_chr)
{
	int		is_escaped;

	i--;
	is_escaped = 0;
	while (str[i] != 0)
	{
		if (str[i] != escp_chr)
			return (is_escaped);
		else
			is_escaped = !is_escaped;
		i--;
	}
	return (str[i] == escp_chr ? !is_escaped : is_escaped);
}
