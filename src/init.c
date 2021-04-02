/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:05:58 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/02 11:43:57 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init(t_fdf *fdf)
{
	t_window	*window;
	t_draw		*draw;
	t_controls	*controls;
	t_colors	*colors;

	ft_bzero(fdf, sizeof(t_fdf));
	ft_check_malloc(window = (t_window *)ft_memalloc(sizeof(t_window)));
	ft_check_malloc(draw = (t_draw *)ft_memalloc(sizeof(t_draw)));
	ft_check_malloc(controls = (t_controls *)ft_memalloc(sizeof(t_controls)));
	ft_check_malloc(colors = (t_colors *)ft_memalloc(sizeof(t_colors)));
	fdf->draw = draw;
	fdf->window = window;
	fdf->controls = controls;
	fdf->colors = colors;
	*ZOOM = 15;
	*ALTITUDE = 1;
	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(MLX_PTR, WIN_WIDTH, WIN_HEIGHT, "FDF");
}
