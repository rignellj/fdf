/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jmpesc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 14:57:28 by ttampio           #+#    #+#             */
/*   Updated: 2020/08/18 17:11:58 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function that increments index (i) by 2 if
** if current character (cur_chr) is escape character (esc_chr)
** and index is less than string length - 1.
** Returns true (1) if jump occurred, false (0) otherwise.
** If the char after the jump is also an escape character, the functions
** is recursively called.
*/

int	ft_jmpesc(char *cur_chr, char esc_chr, size_t *i, size_t strlen)
{
	if (*cur_chr == esc_chr && *i < strlen - 1)
	{
		*i += 2;
		if (*(cur_chr + 2) == esc_chr)
			ft_jmpesc(cur_chr + 2, esc_chr, i, strlen);
		return (1);
	}
	return (0);
}
