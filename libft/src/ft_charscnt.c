/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charscnt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 21:45:42 by ttampio           #+#    #+#             */
/*   Updated: 2021/01/14 18:12:31 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_charscnt(char *s, char *targets)
{
	size_t	i;
	size_t	cnt;

	if (!s)
		return (0);
	i = -1;
	cnt = 0;
	while (s[++i])
		if (ft_isdelim(s[i], targets, 0))
			cnt++;
	return (cnt);
}
