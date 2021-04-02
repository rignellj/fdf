/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_into_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:36:29 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/02 16:55:30 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	write_into_screen(t_fdf *fdf)
{
	mlx_string_put(MLX_PTR, WIN_PTR, 30, 30, WHITE, "How to use:");
	mlx_string_put(MLX_PTR, WIN_PTR, 30, 55 + 15, MAGENTA, "Exit: ESC");
	mlx_string_put(MLX_PTR, WIN_PTR, 30, 80 + 15, MAGENTA,
	"Projections: 1 ISO, 2 DIMETRIC, 3 CONIC, 4 CABINET(30), 5 CABINET(63)");
	mlx_string_put(MLX_PTR, WIN_PTR, 30, 105 + 15, MAGENTA,
	"Altitude (+/-): 'Z' and 'X' Keys");
	mlx_string_put(MLX_PTR, WIN_PTR, 30, 130 + 15, MAGENTA,
	"Hide Map and Reveal: DELETE and ENTER");
	mlx_string_put(MLX_PTR, WIN_PTR, 30, 155 + 15, MAGENTA,
	"Move: Right Click and Arrow Keys");
	mlx_string_put(MLX_PTR, WIN_PTR, 30, 180 + 15, MAGENTA,
	"Zoom In/Out: Mouse Scroll");
}
