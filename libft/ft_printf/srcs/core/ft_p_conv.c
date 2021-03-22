/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:02:41 by ttampio           #+#    #+#             */
/*   Updated: 2019/12/12 13:49:44 by ttampio          ###   ########.fr       */
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

int			ft_p_conv(char *args, va_list ap)
{
	unsigned long	mem_addr;
	char			*str;
	t_mod			mod;
	int				c_to_write;

	mod = ft_map_modifiers(args);
	mem_addr = va_arg(ap, unsigned long);
	str = ft_dec_to_base(16, mem_addr, 0);
	c_to_write = (mem_addr == 0 && !mod.prec) ? 2 : ft_strlen(str) + 2;
	if (!mod.left_adj && mod.min_w - c_to_write > 0)
		ft_add_field_width(mod.min_w - c_to_write);
	if (mem_addr == 0 && !mod.prec)
		ft_putstr("0x");
	else if (mem_addr == 0)
		ft_putstr("0x0");
	else
	{
		ft_putstr("0x");
		ft_putstr(str);
	}
	free(str);
	if (mod.left_adj && mod.min_w - c_to_write > 0)
		ft_add_field_width(mod.min_w - c_to_write);
	return (mod.min_w - c_to_write > 0 ? mod.min_w : c_to_write);
}
