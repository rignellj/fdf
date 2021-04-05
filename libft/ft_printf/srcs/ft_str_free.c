/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 21:11:04 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/03 21:27:18 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static void	do_something(t_format *f, char *tmp, char **new_nbr)
{
	if (*f->nbr == '\0')
		*new_nbr = ft_strdup("\0");
	else
		*new_nbr = ft_strdup(f->nbr);
	ft_check_malloc(*new_nbr);
	ft_strdel(&f->nbr);
	if ((f->width || f->format == 's' || f->format == 'f'))
	{
		f->nbr = ft_strjoin(*new_nbr, tmp);
		ft_check_malloc(f->nbr);
	}
}

void	ft_str_free(t_format *f, char *tmp, int i, int j)
{
	char	*new_nbr;

	if (j && !tmp)
		exit(2);
	if (!i)
	{
		new_nbr = NULL;
		do_something(f, tmp, &new_nbr);
	}
	else
	{
		new_nbr = ft_strdup(f->nbr);
		ft_check_malloc(new_nbr);
		ft_strdel(&f->nbr);
		f->nbr = ft_strjoin(tmp, new_nbr);
	}
	ft_strdel(&tmp);
	ft_strdel(&new_nbr);
}
