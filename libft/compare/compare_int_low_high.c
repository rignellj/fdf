/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_int_low_high.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 16:11:13 by jrignell          #+#    #+#             */
/*   Updated: 2020/12/16 14:01:46 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		compare_int_low_high(void *int1, void *int2)
{
	return (*(int *)int1 - *(int *)int2);
}
