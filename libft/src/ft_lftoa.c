/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lftoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:27:09 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/03 19:12:04 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	add_one_or_int(char *dec, long long *num, int minus, int i)
{
	if (i == 1)
	{
		dec[0] = '0';
		if (minus)
			(*num)--;
		else
			(*num)++;
	}
	else if (i == 2)
	{
		if (dec[0] >= '5' && minus)
			(*num)--;
		else if (dec[0] >= '5' && !minus)
			(*num)++;
		ft_strdel(&dec);
	}
}

static void	ft_round(char *dec)
{
	size_t	len;

	len = ft_strlen(dec) - 1;
	if (dec[len] >= '5' && dec[len] <= '9')
	{
		if (len == 0)
			dec[len]++;
		else
		{
			dec[len - 1]++;
			dec[len] = '0';
		}
	}
	while (--len)
	{
		if (dec[len] >= '0' && dec[len] <= '9')
			break ;
		else if (dec[len] == ':')
		{
			dec[len] = '0';
			dec[len - 1]++;
		}
	}
}

static char	*return_after_point(long double zero_point, int prec)
{
	char	*dec;
	size_t	i;
	size_t	num;
	int		temp;

	dec = ft_strnew(prec + 2);
	i = 0;
	num = 0;
	temp = prec;
	prec++;
	while (prec--)
	{
		zero_point *= 10;
		num = (int)zero_point;
		dec[i++] = num + '0';
		zero_point -= num;
	}
	dec[i] = '\0';
	ft_round(dec);
	if (temp > 0)
		dec[i - 1] = '\0';
	return (dec);
}

static char	*prec_zero(char *dec, char *tmp, long long *num, int minus)
{
	add_one_or_int(dec, num, minus, 2);
	tmp = ft_itoa_base(*num, 10, 0);
	if (*num == 0 && minus == 1)
		dec = ft_strjoin("-", tmp);
	else
		dec = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (dec);
}

char	*ft_lftoa(long double value, size_t precision)
{
	char		*dec;
	long long	num;
	int			minus;
	char		*tmp;

	num = (long int)value;
	tmp = NULL;
	if (value < 0)
		minus = 1;
	else
		minus = 0;
	if (value >= 0)
		value = value - num;
	else
		value = ft_abs(value) - ft_abs(num);
	dec = return_after_point(value, precision);
	if (dec[0] == ':')
		add_one_or_int(dec, &num, minus, 1);
	if (precision == 0)
		return (prec_zero(dec, tmp, &num, minus));
	tmp = ft_joindel(ft_itoa_base(num, 10, 0), ft_strdup("."));
	if (num == 0 && minus)
		tmp = ft_joindel(ft_strdup("-"), tmp);
	return (ft_joindel(tmp, dec));
}
