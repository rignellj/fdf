/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:28:39 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/02 19:58:58 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_key(int key)
{
	return (key == ENTER || key == ENTER_2 || key == ISO || key == CONIC
		|| key == DIMETRIC || key == CABINET30 || key == CABINET63
		|| key == KEY_X || key == KEY_Z || (key >= 123 && key <= 126));
}

static void	arrow_key_press(int key, t_fdf *fdf)
{
	if (key == LEFT_ARROW)
		fdf->controls->move_parallel_x -= PIXELS_TO_MOVE_WITH_ARROW;
	else if (key == RIGHT_ARROW)
		fdf->controls->move_parallel_x += PIXELS_TO_MOVE_WITH_ARROW;
	else if (key == DOWN_ARROW)
		fdf->controls->move_parallel_y += PIXELS_TO_MOVE_WITH_ARROW;
	else
		fdf->controls->move_parallel_y -= PIXELS_TO_MOVE_WITH_ARROW;
}

static void	change_projection(int key, t_fdf *fdf)
{
	if (key == ISO)
		fdf->controls->projection = ISO;
	else if (key == DIMETRIC)
		fdf->controls->projection = DIMETRIC;
	else if (key == CABINET30)
		fdf->controls->projection = CABINET30;
	else if (key == CABINET63)
		fdf->controls->projection = CABINET63;
	else
		fdf->controls->projection = CONIC;
}

static void	change_altitude(int key, t_fdf *fdf)
{
	if (key == KEY_Z)
		fdf->controls->change_altitude++;
	else
		fdf->controls->change_altitude--;
}

int	key_press(int key, t_fdf *fdf)
{
	if (key == ESC)
		exit(0);
	if (key == DELETE || is_key(key))
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	if (key >= 123 && key <= 126)
		arrow_key_press(key, fdf);
	else if (key == KEY_X || key == KEY_Z)
		change_altitude(key, fdf);
	else if (key == ISO || key == DIMETRIC || key == CONIC
		|| key == CABINET30 || key == CABINET63)
		change_projection(key, fdf);
	if (is_key(key))
		expose_hook(fdf);
	return (0);
}
