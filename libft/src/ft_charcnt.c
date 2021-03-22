/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 21:45:42 by ttampio           #+#    #+#             */
/*   Updated: 2020/08/18 17:14:52 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_charcnt(char *s, char target)
{
	size_t	i;
	size_t	cnt;

	if (!s)
		return (0);
	i = -1;
	cnt = 0;
	while (s[++i])
		if (s[i] == target)
			cnt++;
	return (cnt);
}
