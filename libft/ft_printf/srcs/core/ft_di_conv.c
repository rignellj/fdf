/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:01:21 by ttampio           #+#    #+#             */
/*   Updated: 2019/12/12 15:01:35 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_format(t_mod mod, int c_to_write, char first_c_of_str)
{
	int	i;
	int	prefix_written;

	i = -1;
	prefix_written = 0;
	if (mod.zero_pad && !mod.left_adj && mod.prec == -1)
	{
		if (!ft_isdigit(first_c_of_str))
		{
			ft_putchar(first_c_of_str);
			prefix_written = 1;
		}
		while (++i < c_to_write)
			ft_putchar('0');
	}
	else
		while (c_to_write--)
			ft_putchar(' ');
	return (prefix_written);
}

int			ft_di_conv(char *args, va_list ap)
{
	t_mod	mod;
	int		str_len;
	int		c_to_write;
	char	*str;
	int		prefix_written;

	prefix_written = 0;
	mod = ft_map_modifiers(args);
	str = ft_convert_to_str(mod, va_arg(ap, long long), 'i', (t_base){10, 0});
	str_len = ft_strlen(str);
	c_to_write = mod.min_w - str_len;
	if (!mod.left_adj && c_to_write > 0)
		prefix_written = ft_format(mod, c_to_write, str[0]);
	ft_putstr(prefix_written ? str + 1 : str);
	free(str);
	if (mod.left_adj && c_to_write > 0)
		ft_format(mod, c_to_write, 0);
	return (c_to_write > 0 ? str_len + c_to_write : str_len);
}
