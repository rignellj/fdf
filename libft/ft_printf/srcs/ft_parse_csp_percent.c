/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_csp_percent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:29:55 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/03 20:43:19 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static void	ft_print_address(va_list ap, t_format *f)
{
	long long int	address;
	char			*tmp;
	char			*tmp2;

	address = va_arg(ap, long long int);
	if (address == 0)
		f->null = 1;
	else
		f->null = 0;
	tmp = ft_itoa_base_u(address, 16, 0);
	if (tmp == NULL)
		exit(7);
	tmp2 = ft_strjoin("0x", tmp);
	if (tmp2 == NULL)
		exit(7);
	ft_strdel(&tmp);
	f->nbr = tmp2;
}

static void	ft_print_str(va_list ap, t_format *f)
{
	char	*printable;

	printable = va_arg(ap, char *);
	if (printable == 0)
	{
		f->null = 1;
		f->nbr = ft_strdup("(null)");
	}
	else
	{
		f->null = 0;
		f->nbr = ft_strdup(printable);
	}
	if (f->nbr == NULL)
		exit(7);
	printable = NULL;
}

static void	ft_handle_char(va_list ap, t_format *f)
{
	char	str[2];

	if (f->format == '%')
		str[0] = '%';
	else
		str[0] = va_arg(ap, int);
	str[1] = '\0';
	if (str[0] == 0)
		f->null = 1;
	else
		f->null = 0;
	f->nbr = ft_strdup(str);
	if (f->nbr == NULL)
		exit(7);
}

static void	print_char(t_format *f, int *len)
{
	if (f->minus)
	{
		ft_putchar_fd('\0', f->fd);
		ft_putstr_fd(f->nbr, f->fd);
	}
	else
	{
		ft_putstr_fd(f->nbr, f->fd);
		ft_putchar_fd('\0', f->fd);
	}
	*len = ft_strlen(f->nbr) + 1;
}

int	ft_parse_csp_percent(t_format *f, va_list ap)
{
	int		len;

	if (f->format == 'c' || f->format == '%')
		ft_handle_char(ap, f);
	else if (f->format == 's')
		ft_print_str(ap, f);
	else if (f->format == 'p')
		ft_print_address(ap, f);
	if (f->format == 's' && f->dot)
		ft_parse_precision(f);
	if (f->width)
		ft_parse_width(f);
	if (f->format == 'c' && f->null == 1)
		print_char(f, &len);
	else
	{
		ft_putstr_fd(f->nbr, f->fd);
		len = ft_strlen(f->nbr);
	}
	ft_struct_del(f);
	return (len);
}
