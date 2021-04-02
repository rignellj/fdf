/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:56:09 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/02 17:28:24 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	axonometric(t_map *point, t_fdf *fdf)
{
	int		prev_x;
    int		prev_y;
	double	angle;

	prev_x = point->rotated_x;
	prev_y = point->rotated_y;
	angle = PROJECTION == DIMETRIC ? RAD15 : RAD30;
	point->rotated_x = MOUSE_ADD_X + ARROW_ADD_X +
	(prev_x - prev_y) * cos(angle);
	point->rotated_y = MOUSE_ADD_Y + ARROW_ADD_Y +
	-point->rotated_z + (prev_x + prev_y) * sin(angle);
}

static void	cabinet(t_map *point, t_fdf *fdf)
{
	double	x;
    double	y;
    double	z;
	double	angle;

	x = point->rotated_x;
	y = point->rotated_y;
	z = point->rotated_z;
	angle = PROJECTION == CABINET63 ? RAD63 : RAD30;
	point->rotated_x = MOUSE_ADD_X + ARROW_ADD_X + x + 0.5 * z * cos(angle);
	point->rotated_y = MOUSE_ADD_Y + ARROW_ADD_Y + y - 0.5 * z * sin(angle);
}

static void	conic(t_map *point, t_fdf *fdf)
{
	point->rotated_x += MOUSE_ADD_X + ARROW_ADD_X;
	point->rotated_y += MOUSE_ADD_Y + ARROW_ADD_Y;
}

static void	init_values(t_fdf *fdf, int x, int y)
{
	*ROT_X = *X;
	*ROT_Y = *Y;
	*ROT_Z = *Z;
	*ROT_X *= *ZOOM;
	*ROT_Y *= *ZOOM;
	*ROT_Z *= *ALTITUDE;
	*ROT_X -= (MAP_WIDTH * *ZOOM) / 2;
	*ROT_Y -= (MAP_HEIGHT * *ZOOM) / 2;
}

void		rotate(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			init_values(fdf, x, y);
			if (PROJECTION == CONIC)
				conic(&fdf->map[y][x], fdf);
			else if (PROJECTION == CABINET30 || PROJECTION == CABINET63)
				cabinet(&fdf->map[y][x], fdf);
			else
				axonometric(&fdf->map[y][x], fdf);
			x++;
		}
		y++;
	}
}
