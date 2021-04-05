/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:05:58 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/02 19:53:28 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	check_malloc(t_draw *draw, t_controls *controls,
			t_colors *colors)
{
	ft_check_malloc(draw);
	ft_check_malloc(controls);
	ft_check_malloc(colors);
}

void	init(t_fdf *fdf)
{
	t_draw		*draw;
	t_controls	*controls;
	t_colors	*colors;

	ft_bzero(fdf, sizeof(t_fdf));
	draw = (t_draw *)ft_memalloc(sizeof(t_draw));
	controls = (t_controls *)ft_memalloc(sizeof(t_controls));
	colors = (t_colors *)ft_memalloc(sizeof(t_colors));
	check_malloc(draw, controls, colors);
	fdf->draw = draw;
	fdf->controls = controls;
	fdf->colors = colors;
	fdf->controls->zoom = 15;
	fdf->controls->change_altitude = 1;
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF");
}
