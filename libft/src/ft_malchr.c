/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 16:57:08 by ttampio           #+#    #+#             */
/*   Updated: 2020/08/18 17:06:07 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Simple function that copies char <c> into newly created string
** and returns that. Returns NULL if malloc fails.
*/

char	*ft_malchr(char c)
{
	char	*chr_cpy;

	if (!(chr_cpy = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	chr_cpy[0] = c;
	chr_cpy[1] = '\0';
	return (chr_cpy);
}
