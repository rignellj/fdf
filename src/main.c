/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:15:07 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/01 20:40:44 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	int		ret;
	t_fdf	fdf;

	init(&fdf);
	if ((ret = read_from_file(&fdf, ac, av)))
		print_usage();
	mlx_expose_hook(fdf.win_ptr, expose_hook, &fdf);
	mlx_key_hook(fdf.win_ptr, key_press, &fdf);
	mlx_mouse_hook(fdf.win_ptr, mouse_press, &fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
