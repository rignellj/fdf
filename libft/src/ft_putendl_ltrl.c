/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_ltrl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 12:00:26 by ttampio           #+#    #+#             */
/*   Updated: 2020/08/18 16:57:58 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  Basically ft_putendl, but skips carriage returns, and print's newlines
**  as '\n';
*/

void	ft_putendl_ltrl(char const *s)
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
	write(1, "\n", 1);
}
