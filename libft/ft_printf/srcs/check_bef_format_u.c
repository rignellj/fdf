/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bef_format_u.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:29:38 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/03 20:24:31 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static void	ft_check_flags(t_format *f)
{
	if (f->dot)
		ft_parse_precision(f);
	if (f->plus || f->space || f->hash)
		ft_parse_flags(f);
	if (f->width)
		ft_parse_width(f);
	if (!f->nbr)
		exit(5);
}

static void	init(t_format *f, int *upper_or_len, unsigned long long print)
{
	f->sign = '+';
	if (!print)
		f->null = 1;
	else
		f->null = 0;
	if (f->format == 'X')
		*upper_or_len = 1;
	else
		*upper_or_len = 0;
}

int	check_bef_format_u(t_format *f, unsigned long long print)
{
	int		upper_or_len;

	init(f, &upper_or_len, print);
	if (!f->len && f->format == 'o')
		f->nbr = ft_itoa_base((unsigned)print, 8, 0);
	else if (f->len && f->format == 'o')
		hh_h_ll_l_u(f, print, 8, 0);
	else if (!f->len && (f->format == 'x' || f->format == 'X'))
		f->nbr = ft_itoa_base_u((unsigned)print, 16, upper_or_len);
	else if (f->len && (f->format == 'x' || f->format == 'X'))
		hh_h_ll_l_u(f, print, 16, upper_or_len);
	else if (!f->len && f->format == 'u')
		f->nbr = ft_itoa_base_u((unsigned)print, 10, 0);
	else if (f->len && f->format == 'u')
		hh_h_ll_l_u(f, print, 10, 0);
	if (!f->nbr)
		exit(5);
	ft_check_flags(f);
	ft_putstr_fd(f->nbr, f->fd);
	upper_or_len = ft_strlen(f->nbr);
	ft_struct_del(f);
	return (upper_or_len);
}
