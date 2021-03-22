/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 08:46:49 by ttampio           #+#    #+#             */
/*   Updated: 2019/12/12 15:50:16 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_format(t_mod mod, int str_len)
{
	long	spaces;
	int		i;

	if ((str_len < mod.prec && mod.prec != -1) || mod.prec == -1)
		spaces = mod.min_w - str_len;
	else
		spaces = mod.min_w - mod.prec;
	i = 0;
	while (i < spaces)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

static int	ft_print_str(char *content, int c_to_write)
{
	char c_written;

	c_written = 0;
	while (*content && c_to_write)
	{
		ft_putchar(*content);
		c_written++;
		content++;
		c_to_write--;
	}
	return (c_written);
}

int			ft_s_conv(char *args, va_list ap)
{
	t_mod	mod;
	char	*str;
	int		c_written;
	int		c_to_write;
	int		str_len;

	str = va_arg(ap, char*);
	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	mod = ft_map_modifiers(args);
	c_to_write = mod.prec == -1 ? str_len : mod.prec;
	c_written = 0;
	if (!mod.left_adj && mod.min_w != 0)
		c_written += ft_format(mod, str_len);
	c_written += ft_print_str(str, c_to_write);
	if (mod.left_adj && mod.min_w != 0)
		c_written += ft_format(mod, str_len);
	return (c_written);
}
