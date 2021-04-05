/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:49:16 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/02 18:49:19 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	expose_hook(t_fdf *fdf)
{
	write_into_screen(fdf);
	rotate(fdf);
	draw(fdf);
	return (0);
}
