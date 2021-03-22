/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:02:26 by ttampio           #+#    #+#             */
/*   Updated: 2019/12/05 18:02:57 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_add_field_width(size_t n)
{
	while (n)
	{
		ft_putchar(' ');
		n--;
	}
}

int			ft_c_conv(char *args, va_list ap)
{
	t_mod mod;

	mod = ft_map_modifiers(args);
	if (mod.left_adj == FALSE && mod.min_w != 0)
		ft_add_field_width(mod.min_w - 1);
	ft_putchar(va_arg(ap, int));
	if (mod.left_adj == TRUE && mod.min_w != 0)
		ft_add_field_width(mod.min_w - 1);
	return (mod.min_w ? mod.min_w : 1);
}
