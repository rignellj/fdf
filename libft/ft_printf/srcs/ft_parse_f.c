/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:45:25 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/03 20:15:21 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	ft_check_prev_f(t_format *f, long double print, int precision)
{
	int		len;

	if (print == 0)
		f->null = 1;
	else
		f->null = 0;
	f->nbr = ft_lftoa(print, precision);
	if (!f->nbr)
		exit(6);
	if (print >= 0)
		f->sign = '+';
	else
		f->sign = '-';
	if (f->plus || f->space || f->hash)
		ft_parse_flags(f);
	if (f->width)
		ft_parse_width(f);
	if (!f->nbr)
		exit(6);
	ft_putstr_fd(f->nbr, f->fd);
	len = ft_strlen(f->nbr);
	ft_struct_del(f);
	return (len);
}

static int	ft_precision_f(t_format *f)
{
	char	*ptr;
	int		ret;

	if (!f->s_str)
		exit(6);
	ret = 0;
	ptr = ft_strchr(f->s_str, '.');
	if (ptr == NULL)
		return (6);
	ptr++;
	if (!ft_isdigit(*ptr))
	{
		ptr = NULL;
		return (0);
	}
	ret = ft_atoi(ptr);
	ptr = NULL;
	return (ret);
}

int	ft_parse_f(t_format *f, va_list ap)
{
	long double	print;

	if (f->len == 'L')
		print = va_arg(ap, long double);
	else
		print = va_arg(ap, double);
	return (ft_check_prev_f(f, print, ft_precision_f(f)));
}
