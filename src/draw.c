/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:32:34 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/03 21:31:31 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	color(int end_z, t_fdf *fdf)
{
	if (end_z >= fdf->colors->sea5)
		return (WHITE);
	else if (end_z < fdf->colors->sea5 && end_z >= fdf->colors->sea4)
		return (BROWN);
	else if (end_z < fdf->colors->sea4 && end_z >= fdf->colors->sea3)
		return (BLUE);
	else if (end_z < fdf->colors->sea3 && end_z >= fdf->colors->sea2)
		return (GREEN);
	else if (end_z < fdf->colors->sea2 && end_z > fdf->colors->sea)
		return (MAGENTA);
	else if (end_z == fdf->colors->sea)
		return (CYAN);
	else if (end_z < fdf->colors->sea && end_z >= fdf->colors->sea_1)
		return (SEA_LEVEL);
	else if (end_z < fdf->colors->sea_1 && end_z >= fdf->colors->sea_2)
		return (YELLOW);
	else if (end_z < fdf->colors->sea_2 && end_z >= fdf->colors->sea_3)
		return (ORANGE);
	else if (end_z < fdf->colors->sea_3 && end_z >= fdf->colors->sea_5)
		return (RED);
	else if (end_z < fdf->colors->sea_5)
		return (CREAM);
	return (YELLOW);
}

static void	draw_slope_lessthan1(t_map *start, t_fdf *fdf, int color)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = (int)start->rotated_x;
	y = (int)start->rotated_y;
	while (i <= fdf->draw->dx)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, color);
		if (fdf->draw->decision_var > 0)
		{
			fdf->draw->decision_var += 2 * (fdf->draw->dy - fdf->draw->dx);
			y += fdf->draw->slope_y;
		}
		else
			fdf->draw->decision_var += 2 * fdf->draw->dy;
		x += fdf->draw->slope_x;
		i++;
	}
}

static void	draw_slope_morethan1(t_map *start, t_fdf *fdf, int color)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = (int)start->rotated_x;
	y = (int)start->rotated_y;
	while (i <= fdf->draw->dy)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, color);
		if (fdf->draw->decision_var > 0)
		{
			fdf->draw->decision_var += 2 * (fdf->draw->dx - fdf->draw->dy);
			x += fdf->draw->slope_x;
		}
		else
			fdf->draw->decision_var += 2 * fdf->draw->dx;
		y += fdf->draw->slope_y;
		i++;
	}
}

static void	init_draw(t_map *start, t_map *end, t_fdf *fdf)
{
	fdf->draw->dx = ft_abs(end->rotated_x - start->rotated_x);
	fdf->draw->dy = ft_abs(end->rotated_y - start->rotated_y);
	if (end->rotated_y >= start->rotated_y)
		fdf->draw->slope_y = 1;
	else
		fdf->draw->slope_y = -1;
	if (end->rotated_x >= start->rotated_x)
		fdf->draw->slope_x = 1;
	else
		fdf->draw->slope_x = -1;
	if (fdf->draw->dx > fdf->draw->dy)
	{
		fdf->draw->decision_var = 2 * fdf->draw->dy - fdf->draw->dx;
		draw_slope_lessthan1(start, fdf, color(end->z, fdf));
	}
	else
	{
		fdf->draw->decision_var = 2 * fdf->draw->dx - fdf->draw->dy;
		draw_slope_morethan1(start, fdf, color(end->z, fdf));
	}
}

void	draw(t_fdf *fdf)
{
	int		y;
	int		x;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x < fdf->width - 1)
				init_draw(&fdf->map[y][x], &fdf->map[y][x + 1], fdf);
			if (y < fdf->height - 1)
				init_draw(&fdf->map[y][x], &fdf->map[y + 1][x], fdf);
			x++;
		}
		y++;
	}
}
