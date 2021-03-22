/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_print_current.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 16:14:13 by jrignell          #+#    #+#             */
/*   Updated: 2020/08/15 18:42:01 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	rb_print_current(void *item, int color)
{
	if (item && color == RB_BLACK)
		ft_printf(CBLACK"item: %d\n"CRESET, *(int *)item);
	else if (item && color == RB_RED)
		ft_printf(CRED"item: %d\n"CRESET, *(int *)item);
}
