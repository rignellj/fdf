/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:12:06 by jrignell          #+#    #+#             */
/*   Updated: 2021/03/31 17:22:37 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom(int button, t_fdf *fdf)
{
	if (button == ZOOM_IN)
		(*ZOOM) += 8;
	else
		*ZOOM = *ZOOM > 8 ? *ZOOM - 8 : 1;
	mlx_clear_window(MLX_PTR, WIN_PTR);
	expose_hook(fdf);
}

static void	set_relative_position(int x, int y, t_fdf *fdf)
{
	MOUSE_ADD_X = x;
	MOUSE_ADD_Y = y;
	mlx_clear_window(MLX_PTR, WIN_PTR);
	expose_hook(fdf);
}

int			mouse_press(int button, int x, int y, t_fdf *fdf)
{
	if (button == ZOOM_IN || button == ZOOM_OUT)
		zoom(button, fdf);
	else if (button == MOUSE_LEFT)
		set_relative_position(x, y, fdf);
	return (0);
}
