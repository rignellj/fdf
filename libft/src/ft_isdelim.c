/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdelim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 22:15:26 by ttampio           #+#    #+#             */
/*   Updated: 2020/07/26 22:15:30 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns true (1) if array of chars <chrarr> contains char <c>,
** false (0) otherwise.
*/

int	ft_isdelim(char c, char *chrarr, int incl_spaces)
{
	size_t	i;

	i = -1;
	while (chrarr[++i])
		if (chrarr[i] == c || (incl_spaces && ft_isspace(c)))
			return (1);
	return (0);
}
