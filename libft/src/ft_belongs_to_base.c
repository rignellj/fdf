/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_belongs_to_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:52:18 by jrignell          #+#    #+#             */
/*   Updated: 2021/01/26 14:52:52 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_belongs_to_base(char c, int base)
{
	char	*s1;
	char	*s2;

	if (base <= 36)
	{
		s1 = "0123456789abcdefghijklmnopqrstuvwxyz";
		s2 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	}
	else
	{
		s1 = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ@_";
		s2 = s1;
	}
	while (base--)
	{
		if (s1[base] == c || s2[base] == c)
			return (1);
	}
	return (0);
}
