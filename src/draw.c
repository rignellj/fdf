/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:32:34 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/02 17:21:50 by jrignell         ###   ########.fr       */
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
	while (i <= DX)
	{
		mlx_pixel_put(MLX_PTR, WIN_PTR, x, y, color);
		if (DECISION_VAR > 0)
		{
			DECISION_VAR = DECISION_VAR + 2 * (DY - DX);
			y += SLOPE_Y;
		}
		else
			DECISION_VAR = DECISION_VAR + 2 * DY;
		x += SLOPE_X;
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
	while (i <= DY)
	{
		mlx_pixel_put(MLX_PTR, WIN_PTR, x, y, color);
		if (DECISION_VAR > 0)
		{
			DECISION_VAR = DECISION_VAR + 2 * (DX - DY);
			x += SLOPE_X;
		}
		else
			DECISION_VAR = DECISION_VAR + 2 * DX;
		y += SLOPE_Y;
		i++;
	}
}

static void	init_draw(t_map *start, t_map *end, t_fdf *fdf)
{
	DX = ft_abs(end->rotated_x - start->rotated_x);
	DY = ft_abs(end->rotated_y - start->rotated_y);
	SLOPE_Y = end->rotated_y >= start->rotated_y ? 1 : -1;
	SLOPE_X = end->rotated_x >= start->rotated_x ? 1 : -1;
	if (DX > DY)
	{
		DECISION_VAR = 2 * DY - DX;
		draw_slope_lessthan1(start, fdf, color(end->z, fdf));
	}
	else
	{
		DECISION_VAR = 2 * DX - DY;
		draw_slope_morethan1(start, fdf, color(end->z, fdf));
	}
}

void		draw(t_fdf *fdf)
{
	int		y;
	int		x;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			if (x < MAP_WIDTH - 1)
				init_draw(START, END_R, fdf);
			if (y < MAP_HEIGHT - 1)
				init_draw(START, END_D, fdf);
			x++;
		}
		y++;
	}
}
