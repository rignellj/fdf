/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 12:20:05 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/03 21:12:06 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_zero(t_format *f)
{
	ft_bzero(f, sizeof(t_format));
}

void	swap_chars(t_format *f)
{
	int		i;

	i = 0;
	while (f->nbr[i] && f->nbr[0] == '0')
	{
		if (f->nbr[i] == '+')
		{
			f->nbr[i] = '0';
			*f->nbr = '+';
			return ;
		}
		else if (f->nbr[i] == '-')
		{
			f->nbr[i] = '0';
			*f->nbr = '-';
			return ;
		}
		else if (f->nbr[i] == ' ' && ft_isdigit(f->nbr[i + 1]))
		{
			f->nbr[i] = '0';
			*f->nbr = ' ';
			return ;
		}
		i++;
	}
}

void	swap_0x(t_format *f)
{
	char	*c;
	char	*b;

	c = ft_strchr(f->s_str, 'X');
	if (!c)
	{
		c = ft_strchr(f->s_str, 'x');
		if (!c)
			return ;
	}
	b = ft_strchr(f->nbr, *c);
	if (!b)
		return ;
	if (f->nbr[0] == '0' && f->nbr[1] != *c && b)
	{
		f->nbr[1] = *c;
		*b = '0';
	}
}

void	ft_struct_del(t_format *f)
{
	if (f->s_str)
		ft_strdel(&f->s_str);
	if (f->nbr)
	{
		free(f->nbr);
		f->nbr = NULL;
	}
	f = NULL;
}
