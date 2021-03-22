/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isquote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:36:23 by ttampio           #+#    #+#             */
/*   Updated: 2020/08/18 17:13:25 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns 1 if value of c corresponds to `'`, 2 if `"`, 0 otherwise.
*/

int	ft_isquote(int c)
{
	if (c == '\'')
		return (1);
	else if (c == '\"')
		return (2);
	return (0);
}
