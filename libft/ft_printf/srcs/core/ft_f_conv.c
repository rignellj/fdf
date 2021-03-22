/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 11:59:18 by ttampio           #+#    #+#             */
/*   Updated: 2019/12/16 10:39:42 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_print_sign(int is_negative, int space, int sign)
{
	if (is_negative || space || sign)
	{
		if (is_negative)
			ft_putchar('-');
		else if (sign)
			ft_putchar('+');
		else if (space)
			ft_putchar(' ');
		return (1);
	}
	return (0);
}

static int	ft_print_fill(int fill_to_write, int zero_pad)
{
	int	c_written;

	c_written = 0;
	while (fill_to_write--)
	{
		ft_putchar(zero_pad ? '0' : ' ');
		c_written++;
	}
	return (c_written);
}

static int	ft_print_value(char *digit_str, int prec, int str_len, \
							int print_dot)
{
	int	i;
	int	whole_num;
	int	zeros_after_dot;

	whole_num = str_len - prec;
	zeros_after_dot = prec - str_len;
	i = 0;
	if (whole_num <= 0)
		ft_putchar('0');
	else
		while (whole_num > i)
			ft_putchar(digit_str[i++]);
	if (print_dot)
		ft_putchar('.');
	while (zeros_after_dot-- > 0)
		ft_putchar('0');
	while (digit_str[i])
		ft_putchar(digit_str[i++]);
	return (prec + print_dot + (whole_num <= 0 ? 1 : whole_num));
}

static int	ft_handle_print(long db_value, t_mod mod, int is_negative)
{
	int		c_written;
	int		fill_to_write;
	char	*digit_str;
	int		str_len;
	int		print_dot;

	c_written = 0;
	print_dot = (!(mod.prec == 0 && !mod.hash));
	digit_str = ft_lltoa((long long)db_value);
	str_len = ft_strlen(digit_str);
	fill_to_write = mod.min_w - (mod.space || mod.sign || is_negative) - \
	mod.prec - print_dot - (str_len - mod.prec < 0 ? 1 : str_len - mod.prec);
	if (mod.zero_pad && (is_negative || mod.space || mod.sign))
		c_written += ft_print_sign(is_negative, mod.space, mod.sign);
	if (!mod.left_adj && fill_to_write > 0)
		c_written += ft_print_fill(fill_to_write, mod.zero_pad);
	if (!mod.zero_pad)
		c_written += ft_print_sign(is_negative, mod.space, mod.sign);
	c_written += ft_print_value(digit_str, mod.prec, str_len, print_dot);
	if (mod.left_adj && fill_to_write > 0)
		c_written += ft_print_fill(fill_to_write, 0);
	free(digit_str);
	return (c_written);
}

int			ft_f_conv(char *args, va_list ap)
{
	t_mod		mod;
	long double	db_value;
	int			c_written;
	int			is_negative;

	is_negative = 0;
	c_written = 0;
	mod = ft_map_modifiers(args);
	mod.prec = mod.prec == -1 ? 6 : mod.prec;
	if (mod.len_mod && ft_strcmp(mod.len_mod, "L") == 0)
		db_value = va_arg(ap, long double);
	else
		db_value = va_arg(ap, double);
	if (db_value < 0)
	{
		db_value = -db_value;
		is_negative = 1;
	}
	db_value = ft_mask_decimal_trail(db_value, mod.prec);
	db_value = ft_power_of_ten(mod.prec) * db_value;
	if ((unsigned long long)(db_value + 0.5) > (unsigned long long)db_value)
		db_value = db_value + 0.5;
	c_written = ft_handle_print((unsigned long long)db_value, mod, is_negative);
	return (c_written);
}
