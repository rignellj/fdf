/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:51:50 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/03 21:04:48 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	define_dot_minus_space_plus(t_format *f)
{
	if (ft_strchr(f->s_str, '.'))
		f->dot = 1;
	else
		f->dot = 0;
	if (ft_strchr(f->s_str, '-'))
		f->minus = 1;
	else
		f->minus = 0;
	if (ft_strchr(f->s_str, ' '))
		f->space = 1;
	else
		f->space = 0;
	if (ft_strchr(f->s_str, '+'))
		f->plus = 1;
	else
		f->plus = 0;
}

static void	define_hash_precision_width(t_format *f)
{
	if (ft_strchr(f->s_str, '#'))
		f->hash = 1;
	else
		f->hash = 0;
	if (f->dot)
		f->prec = ft_if_precision_diouxs(f);
	else
		f->prec = 0;
	if (ft_strchr(f->s_str, ' '))
		f->space = 1;
	else
		f->space = 0;
	if (ft_strchr(f->s_str, '+'))
		f->plus = 1;
	else
		f->plus = 0;
	f->width = ft_check_if_width(f);
}

void	ft_form_struct(t_format *f, char *format, unsigned i, unsigned j)
{
	char	c;

	ft_put_zero(f);
	f->s_str = ft_strsub(format, i, j);
	if (!f->s_str)
		exit(-1);
	f->format = f->s_str[ft_strlen(f->s_str) - 1];
	c = f->format;
	f->len = which_len(f);
	define_dot_minus_space_plus(f);
	define_hash_precision_width(f);
	if ((f->minus || (f->dot && (c == 'd' || c == 'i' || c == 'o'
					|| c == 'u' || c == 'x' || c == 'X'))))
		f->zero = 0;
	else
		f->zero = iszero(f);
}
