/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:56:09 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/03 21:30:50 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	axonometric(t_map *point, t_fdf *fdf)
{
	int			prev_x;
	int			prev_y;
	double		angle;

	prev_x = point->rotated_x;
	prev_y = point->rotated_y;
	if (fdf->controls->projection == DIMETRIC)
		angle = RAD15;
	else
		angle = RAD30;
	point->rotated_x = fdf->controls->fixed_dx + fdf->controls->move_parallel_x
		+ (prev_x - prev_y) * cos(angle);
	point->rotated_y = fdf->controls->fixed_dy + fdf->controls->move_parallel_y
		+ -point->rotated_z + (prev_x + prev_y) * sin(angle);
}

static void	cabinet(t_map *point, t_fdf *fdf)
{
	double		x;
	double		y;
	double		z;
	double		angle;

	x = point->rotated_x;
	y = point->rotated_y;
	z = point->rotated_z;
	if (fdf->controls->projection == CABINET63)
		angle = RAD63;
	else
		angle = RAD30;
	point->rotated_x = fdf->controls->fixed_dx + fdf->controls->move_parallel_x
		+ x + 0.5 * z * cos(angle);
	point->rotated_y = fdf->controls->fixed_dy + fdf->controls->move_parallel_y
		+ y - 0.5 * z * sin(angle);
}

static void	conic(t_map *point, t_fdf *fdf)
{
	point->rotated_x += fdf->controls->fixed_dx
		+ fdf->controls->move_parallel_x;
	point->rotated_y += fdf->controls->fixed_dy
		+ fdf->controls->move_parallel_y;
}

static void	init_values(t_fdf *fdf, int x, int y)
{
	fdf->map[y][x].rotated_x = fdf->map[y][x].x;
	fdf->map[y][x].rotated_y = fdf->map[y][x].y;
	fdf->map[y][x].rotated_z = fdf->map[y][x].z;
	fdf->map[y][x].rotated_x *= fdf->controls->zoom;
	fdf->map[y][x].rotated_y *= fdf->controls->zoom;
	fdf->map[y][x].rotated_z *= fdf->controls->change_altitude;
	fdf->map[y][x].rotated_x -= (fdf->width * fdf->controls->zoom) / 2;
	fdf->map[y][x].rotated_y -= (fdf->height * fdf->controls->zoom) / 2;
}

void	rotate(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			init_values(fdf, x, y);
			if (fdf->controls->projection == CONIC)
				conic(&fdf->map[y][x], fdf);
			else if (fdf->controls->projection == CABINET30
				|| fdf->controls->projection == CABINET63)
				cabinet(&fdf->map[y][x], fdf);
			else
				axonometric(&fdf->map[y][x], fdf);
			x++;
		}
		y++;
	}
}
