/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 09:32:48 by ttampio           #+#    #+#             */
/*   Updated: 2020/08/18 17:05:49 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_format(t_mod mod, int c_to_write, char first_c_of_str)
{
	int i;

	i = -1;
	if (mod.zero_pad && !mod.left_adj && mod.prec == -1)
	{
		if (!ft_isdigit(first_c_of_str))
			ft_putchar(first_c_of_str);
		while (++i < c_to_write)
			ft_putchar('0');
	}
	else
		while (c_to_write--)
			ft_putchar(' ');
}

int			ft_u_conv(char *args, va_list ap)
{
	t_mod	mod;
	int		str_len;
	int		c_to_write;
	char	*str;

	mod = ft_map_modifiers(args);
	str = ft_convert_to_str(mod, va_arg(ap, long long), 'u', (t_base){10, 0});
	str_len = ft_strlen(str);
	c_to_write = mod.min_w - str_len;
	if (!mod.left_adj && c_to_write > 0)
		ft_format(mod, c_to_write, str[0]);
	ft_putstr(str);
	free(str);
	if (mod.left_adj && c_to_write > 0)
		ft_format(mod, c_to_write, 0);
	return (c_to_write > 0 ? (str_len + c_to_write) : str_len);
}
