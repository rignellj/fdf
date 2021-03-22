/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:19:58 by ttampio           #+#    #+#             */
/*   Updated: 2020/12/16 14:00:49 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../../includes/libft.h"
# include <stdarg.h>

# define CONV_COUNT 11
# define CONVERSIONS "cspdiouxXf%"

typedef int		(*t_func)(char*, va_list);

typedef int		t_bool;
# define TRUE 1
# define FALSE 0

typedef struct	s_dispatcher
{
	char		conv_specifier;
	t_func		func;
}				t_dispatcher;

typedef struct	s_base
{
	int			num;
	int			to_uppcase;
}				t_base;

typedef struct	s_mod
{
	t_bool		hash;
	t_bool		zero_pad;
	t_bool		left_adj;
	t_bool		sign;
	t_bool		space;
	int			min_w;
	int			prec;
	char		*len_mod;
	int			err_index;
}				t_mod;

/*
** Core functions
*/

int				ft_printf(const char *format, ...);
t_mod			ft_map_modifiers(char *args);
char			*ft_convert_to_str(t_mod mod, long long content, char type, \
							t_base base);
int				ft_c_conv(char *args, va_list ap);
int				ft_s_conv(char *args, va_list ap);
int				ft_p_conv(char *args, va_list ap);
int				ft_di_conv(char *args, va_list ap);
int				ft_o_conv(char *args, va_list ap);
int				ft_u_conv(char *args, va_list ap);
int				ft_x_conv(char *args, va_list ap);
int				ft_upr_x_conv(char *args, va_list ap);
int				ft_f_conv(char *args, va_list ap);
int				ft_percent_conv(char *args, va_list ap);

/*
** Helpers
*/

long double		ft_mask_decimal_trail(long double db_value, int prec);

#endif
