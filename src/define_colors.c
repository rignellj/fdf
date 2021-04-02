/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:01:58 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/02 17:16:39 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	define_levels(int *max, int *min, t_fdf *fdf)
{
	int		range;
	double	adjust_factor_1;
	double	adjust_factor_2;
	double	decile;

	range = ft_abs(*max - *min);
	decile = range / 10;
	adjust_factor_1 = ft_abs(*max / (decile * 5));
	adjust_factor_2 = ft_abs(*min / (decile * 5));
	fdf->colors->sea = 0;
	fdf->colors->sea1 = adjust_factor_1 * decile;
	fdf->colors->sea_1 = adjust_factor_2 * -decile;
	fdf->colors->sea2 = adjust_factor_1 * 2 * decile;
	fdf->colors->sea_2 = adjust_factor_2 * -2 * decile;
	fdf->colors->sea3 = adjust_factor_1 * 3 * decile;
	fdf->colors->sea_3 = adjust_factor_2 * -3 * decile;
	fdf->colors->sea4 = adjust_factor_1 * 4 * decile;
	fdf->colors->sea_4 = adjust_factor_2 * -4 * decile;
	fdf->colors->sea5 = adjust_factor_1 * 5 * decile;
	fdf->colors->sea_5 = adjust_factor_2 * -5 * decile;
}

static void	define_max_min(t_map *current, int *max, int *min)
{
	if (current->z > *max)
		*max = current->z;
	else if (current->z < *min)
		*min = current->z;
}

void		define_colors(t_fdf *fdf)
{
	int		x;
	int		y;
	int		max_min[2];

	y = 0;
	max_min[0] = 0;
	max_min[1] = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			define_max_min(&fdf->map[y][x], &max_min[0], &max_min[1]);
			x++;
		}
		y++;
	}
	define_levels(&max_min[0], &max_min[1], fdf);
}
