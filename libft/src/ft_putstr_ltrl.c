/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ltrl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 11:52:16 by ttampio           #+#    #+#             */
/*   Updated: 2020/08/18 16:51:41 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  Basically ft_putstr, but skips carriage returns, and print's newlines
**  as '\n';
*/

void	ft_putstr_ltrl(char const *s)
{
	size_t	i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
	{
		if (s[i] == '\r')
			continue;
		else if (s[i] == '\n')
			write(1, "\\n", 2);
		else
			write(1, &s[i], 1);
	}
}
