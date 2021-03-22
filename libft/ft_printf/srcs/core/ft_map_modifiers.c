/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_modifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 09:49:43 by ttampio           #+#    #+#             */
/*   Updated: 2020/11/05 20:18:48 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_check_start_flags(char *args, t_mod *mod)
{
	int i;

	i = 0;
	while (args[i] && ft_strchri("0 =+-#", args[i]) != -1)
	{
		if (args[i] == '0')
			mod->zero_pad = 1;
		else if (args[i] == ' ')
			mod->space = 1;
		else if (args[i] == '+')
			mod->sign = 1;
		else if (args[i] == '-')
			mod->left_adj = 1;
		else if (args[i] == '#')
			mod->hash = 1;
		i++;
	}
	return (i);
}

static int	ft_check_min_w(char *args, t_mod *mod)
{
	int i;
	int done;

	i = 0;
	done = FALSE;
	while (args[i] && ft_isdigit(args[i]))
	{
		if (args[i] != '0' && !done)
		{
			mod->min_w = ft_atoi(args + i);
			done = TRUE;
		}
		i++;
	}
	return (i);
}

static int	ft_check_prec(char *args, t_mod *mod)
{
	int i;
	int done;

	i = 0;
	done = FALSE;
	while (args[i] && ft_strchri(".1234567890", args[i]) != -1)
	{
		if (!done && (args[i] == '.' || args[i] == '0'))
			mod->prec = 0;
		else if (args[i] != '0' && ft_isdigit(args[i]) && !done)
		{
			mod->prec = ft_atoi(args + i);
			done = TRUE;
		}
		i++;
	}
	return (i);
}

static int	ft_check_lngth_mod(char *args, t_mod *mod)
{
	int i;

	i = 0;
	while (args[i] && ft_strchri("hlL", args[i]) != -1)
		i++;
	if (i > 0)
	{
		if (ft_strncmp("l", args, i) == 0)
			mod->len_mod = "l";
		else if (ft_strncmp("L", args, i) == 0)
			mod->len_mod = "L";
		else if (ft_strncmp("h", args, i) == 0)
			mod->len_mod = "h";
		else if (ft_strncmp("ll", args, i) == 0)
			mod->len_mod = "ll";
		else if (ft_strncmp("hh", args, i) == 0)
			mod->len_mod = "hh";
	}
	return (i);
}

t_mod		ft_map_modifiers(char *args)
{
	t_mod	mod;
	int		skip;

	mod.hash = FALSE;
	mod.zero_pad = FALSE;
	mod.left_adj = FALSE;
	mod.sign = FALSE;
	mod.space = FALSE;
	mod.min_w = 0;
	mod.prec = -1;
	mod.err_index = -1;
	mod.len_mod = NULL;
	if (ft_strlen(args) == 0)
		return (mod);
	skip = ft_check_start_flags(args, &mod);
	skip += ft_check_min_w(args + skip, &mod);
	skip += ft_check_prec(args + skip, &mod);
	ft_check_lngth_mod(args + skip, &mod);
	return (mod);
}
