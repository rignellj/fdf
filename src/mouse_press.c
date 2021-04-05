/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:12:06 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/02 19:59:23 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom(int button, t_fdf *fdf)
{
	if (button == ZOOM_IN)
		fdf->controls->zoom += 8;
	else
	{
		if (fdf->controls->zoom > 8)
			fdf->controls->zoom -= 8;
		else
			fdf->controls->zoom = 1;
	}
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	expose_hook(fdf);
}

static void	set_relative_position(int x, int y, t_fdf *fdf)
{
	fdf->controls->fixed_dx = x;
	fdf->controls->fixed_dy = y;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	expose_hook(fdf);
}

int	mouse_press(int button, int x, int y, t_fdf *fdf)
{
	if (button == ZOOM_IN || button == ZOOM_OUT)
		zoom(button, fdf);
	else if (button == MOUSE_LEFT)
		set_relative_position(x, y, fdf);
	return (0);
}
