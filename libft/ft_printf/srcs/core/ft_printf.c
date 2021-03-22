/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:16:17 by ttampio           #+#    #+#             */
/*   Updated: 2020/08/15 17:15:36 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_func	ft_return_func_ptr(char c, t_dispatcher d[CONV_COUNT])
{
	int i;

	i = 0;
	while (c != d[i].conv_specifier && i < CONV_COUNT)
		i++;
	if (c != d[i].conv_specifier)
		return (NULL);
	return (d[i].func);
}

static int		ft_handle_conversion(const char *fmt, \
				t_dispatcher d[CONV_COUNT], va_list ap, int *n_written)
{
	int		i;
	char	*args;
	t_func	func;

	i = 1;
	while (ft_strchri(CONVERSIONS, fmt[i]) == -1 && fmt[i])
		i++;
	if (fmt[i] == '\0')
		return (0);
	func = ft_return_func_ptr(fmt[i], d);
	if (func == NULL)
		return (i);
	args = ft_strsub(fmt, 1, i - 1);
	*n_written += func(args, ap);
	free(args);
	return (i);
}

static void		ft_initialize_dispatcher(t_dispatcher d[CONV_COUNT])
{
	d[0] = (t_dispatcher){'c', &ft_c_conv};
	d[1] = (t_dispatcher){'s', &ft_s_conv};
	d[2] = (t_dispatcher){'p', &ft_p_conv};
	d[3] = (t_dispatcher){'d', &ft_di_conv};
	d[4] = (t_dispatcher){'i', &ft_di_conv};
	d[5] = (t_dispatcher){'o', &ft_o_conv};
	d[6] = (t_dispatcher){'u', &ft_u_conv};
	d[7] = (t_dispatcher){'x', &ft_x_conv};
	d[8] = (t_dispatcher){'X', &ft_upr_x_conv};
	d[9] = (t_dispatcher){'f', &ft_f_conv};
	d[10] = (t_dispatcher){'%', &ft_percent_conv};
}

void			ft_handle_write(char c, int *n_written)
{
	*n_written += 1;
	ft_putchar(c);
}

int				ft_printf(const char *format, ...)
{
	va_list			ap;
	t_dispatcher	d[CONV_COUNT];
	int				n_written;

	n_written = 0;
	ft_initialize_dispatcher(d);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			format += ft_handle_conversion(format, d, ap, &n_written);
		else
			ft_handle_write(*format, &n_written);
		format++;
	}
	va_end(ap);
	return (n_written);
}
