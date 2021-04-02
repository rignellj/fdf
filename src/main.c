/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:15:07 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/02 13:55:15 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	t_fdf	fdf;

	init(&fdf);
	if ((read_from_file(&fdf, ac, av)))
		print_usage();
	define_colors(&fdf);
	mlx_expose_hook(fdf.win_ptr, expose_hook, &fdf);
	mlx_key_hook(fdf.win_ptr, key_press, &fdf);
	mlx_mouse_hook(fdf.win_ptr, mouse_press, &fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
