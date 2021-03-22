/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 10:13:44 by ttampio           #+#    #+#             */
/*   Updated: 2019/12/12 16:07:53 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_format(t_mod mod, int c_to_write)
{
	int i;

	i = -1;
	if (mod.zero_pad && !mod.left_adj && mod.prec == -1)
		while (++i < c_to_write)
			ft_putchar('0');
	else
		while (c_to_write--)
			ft_putchar(' ');
}

int			ft_x_conv(char *args, va_list ap)
{
	t_mod	mod;
	int		str_len;
	int		c_to_write;
	char	*str;

	mod = ft_map_modifiers(args);
	str = ft_convert_to_str(mod, va_arg(ap, long long), 'u', (t_base){16, 0});
	str_len = ft_strlen(str) + (mod.hash && \
	ft_contains_chrs(str, "123456789abcdef") ? 2 : 0);
	c_to_write = mod.min_w - str_len;
	if (mod.hash && mod.zero_pad && ft_contains_chrs(str, "123456789abcdef"))
		ft_putstr("0x");
	if (!mod.left_adj && c_to_write > 0)
		ft_format(mod, c_to_write);
	if (mod.hash && !mod.zero_pad && ft_contains_chrs(str, "123456789abcdef"))
		ft_putstr("0x");
	ft_putstr(str);
	free(str);
	if (mod.left_adj && c_to_write > 0)
		ft_format(mod, c_to_write);
	return (c_to_write > 0 ? (str_len + c_to_write) : str_len);
}
