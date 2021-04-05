/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:36:21 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/03 19:29:51 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static void	ft_join_free_old(t_format *f, char *tmp)
{
	char	*s1;

	if (f->minus)
		s1 = ft_strjoin(f->nbr, tmp);
	else
		s1 = ft_strjoin(tmp, f->nbr);
	if (!s1)
		exit(4);
	ft_strdel(&f->nbr);
	f->nbr = s1;
	ft_strdel(&tmp);
}

static char	ft_return_char(t_format *f)
{
	if (f->minus)
		return (' ');
	if (f->zero && f->format == 'f')
		return ('0');
	if (f->zero && f->format != 'c' && f->format != 's'
		&& f->format != 'p' && !f->prec)
		return ('0');
	return (' ');
}

static void	width(t_format *f)
{
	char	*tmp;
	int		len;
	size_t	i;
	char	flag;

	i = 0;
	flag = ft_return_char(f);
	len = (int)ft_strlen(f->nbr);
	tmp = ft_strnew(f->width - len);
	if (!tmp)
		exit(4);
	while (f->width > len++)
		tmp[i++] = flag;
	ft_join_free_old(f, tmp);
}

void	ft_parse_width(t_format *f)
{
	int		len;
	char	*tmp;
	int		i;

	tmp = NULL;
	len = (int)ft_strlen(f->nbr);
	if (f->format == 'c' && f->null == 1)
		f->width -= 1;
	else
		f->width -= 0;
	if (len >= f->width && f->format != 's')
		return ;
	i = 0;
	if (f->prec >= f->width && f->format != 's')
		return ;
	if (f->width > len)
		width(f);
	if (f->format == 'd' || f->format == 'i' || f->format == 'f')
		swap_chars(f);
	else
		swap_0x(f);
}
