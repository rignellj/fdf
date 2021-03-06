/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bef_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:26:13 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/03 20:31:17 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	print_free_return(t_format *f)
{
	int		len;

	ft_putstr_fd(f->nbr, f->fd);
	len = ft_strlen(f->nbr);
	ft_struct_del(f);
	return (len);
}

int	check_bef_format(t_format *f, long long print)
{
	if (print == 0)
		f->null = 1;
	else
		f->null = 0;
	if (!f->len)
		f->nbr = ft_itoa_base((int)print, 10, 0);
	else
		hh_h_ll_l(f, print, 10, 0);
	if (!f->nbr)
		exit(1);
	if (print < 0)
		f->sign = '-';
	else
		f->sign = '+';
	if (f->dot)
		ft_parse_precision(f);
	if (f->plus || f->space || f->hash)
		ft_parse_flags(f);
	if (f->width)
		ft_parse_width(f);
	return (print_free_return(f));
}
