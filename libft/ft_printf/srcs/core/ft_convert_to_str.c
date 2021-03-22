/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:09:55 by ttampio           #+#    #+#             */
/*   Updated: 2019/12/12 13:54:02 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_add_precision(char **str, int prec, int digits, int minus_sign)
{
	char *zeros;
	char *tmp;

	zeros = ft_strnew((prec - digits) + minus_sign);
	ft_memset(zeros + minus_sign, '0', prec - digits);
	if (minus_sign)
		zeros[0] = '-';
	tmp = *str;
	if (!(*str = ft_strjoin(zeros, *str + minus_sign)))
		exit(1);
	free(zeros);
	free(tmp);
}

static void	ft_add_sign_space(char **str, t_bool sign)
{
	char *prefix;
	char *tmp;

	prefix = sign ? ft_strdup("+") : ft_strdup(" ");
	tmp = *str;
	if (!(*str = ft_strjoin(prefix, *str)))
		exit(1);
	free(prefix);
	free(tmp);
}

static char	*ft_handle_modify_dioux_str(t_mod mod, char *str, char type)
{
	int str_len;
	int	minus_sign;
	int	digits;

	str_len = ft_strlen(str);
	minus_sign = str[0] == '-' ? 1 : 0;
	digits = minus_sign ? str_len - 1 : str_len;
	if (!mod.prec && ft_strcmp("0", str) == 0)
	{
		free(str);
		str = ft_strnew(0);
	}
	if (mod.prec > digits)
		ft_add_precision(&str, mod.prec, digits, minus_sign);
	if (!minus_sign && (mod.sign || mod.space) && type == 'i')
		ft_add_sign_space(&str, mod.sign);
	return (str);
}

/*
** Converts number to string and handles possible "+", " ",
** precision and length modifiers.
*/

char		*ft_convert_to_str(t_mod mod, long long content, char type, \
							t_base base)
{
	char *str;

	if (mod.len_mod && ft_strcmp(mod.len_mod, "h") == 0)
		str = type == 'i' \
		? ft_lltoa((short)content) \
		: ft_dec_to_base(base.num, (unsigned short)content, base.to_uppcase);
	else if (mod.len_mod && ft_strcmp(mod.len_mod, "hh") == 0)
		str = type == 'i' \
		? ft_lltoa((char)content) \
		: ft_dec_to_base(base.num, (unsigned char)content, base.to_uppcase);
	else if (mod.len_mod && ft_strcmp(mod.len_mod, "l") == 0)
		str = type == 'i' \
		? ft_lltoa((long)content) \
		: ft_dec_to_base(base.num, (unsigned long)content, base.to_uppcase);
	else if (mod.len_mod && ft_strcmp(mod.len_mod, "ll") == 0)
		str = type == 'i' \
		? ft_lltoa((long long)content) \
		: ft_dec_to_base(base.num, (unsigned long)content, base.to_uppcase);
	else if (type == 'i')
		str = ft_lltoa((int)content);
	else
		str = ft_dec_to_base(base.num, (unsigned int)content, base.to_uppcase);
	str = ft_handle_modify_dioux_str(mod, str, type);
	return (str);
}
