/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:13:23 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/01 18:50:28 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** Includes
*/

# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "keys.h"
# include "libft.h"

# define BLUE 0x0000FF
# define GREEN 0X00FF00
# define WHITE 0xFFFFFFF
# define YELLOW 0xFFFF00
# define HIGHEST 0xCB7F57
# define HIGHEST_1 0xE19067
# define HIGHEST_2 0xFFA76D
# define HIGHEST_3 0xFFBE93
# define HIGHEST_4 0xFFD5AE
# define SEA_LEVEL 0xFFEDD5
# define SEA_LEVEL_1 0xE2F5FC
# define SEA_LEVEL_2 0xCBEDFB
# define SEA_LEVEL_3 0xAFE3F9
# define SEA_LEVEL_4 0x8ED9F6
# define SEA_LEVEL_5 0x68CEF3

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080
# define PIXELS_TO_MOVE_WITH_ARROW 45

# define MAP_WIDTH fdf->window->width
# define MAP_HEIGHT fdf->window->height
# define MLX_PTR fdf->mlx_ptr
# define WIN_PTR fdf->win_ptr

# define START &fdf->map[y][x]
# define Y &fdf->map[y][x].y
# define X &fdf->map[y][x].x
# define Z &fdf->map[y][x].z
# define ROT_Y &fdf->map[y][x].rotated_y
# define ROT_X &fdf->map[y][x].rotated_x
# define ROT_Z &fdf->map[y][x].rotated_z
# define END_R &fdf->map[y][x + 1]
# define END_D &fdf->map[y + 1][x]
# define RAD63 1.107149
# define RAD45 0.758398
# define RAD30 0.523599
# define RAD15 0.261799

# define DECISION_VAR fdf->draw->decision_var
# define DX fdf->draw->dx
# define DY fdf->draw->dy
# define SLOPE_Y fdf->draw->slope_y
# define SLOPE_X fdf->draw->slope_x

# define ZOOM &fdf->controls->zoom
# define ALTITUDE &fdf->controls->change_altitude
# define MOUSE_ADD_X fdf->controls->fixed_dx
# define MOUSE_ADD_Y fdf->controls->fixed_dy
# define ARROW_ADD_X fdf->controls->move_parallel_x
# define ARROW_ADD_Y fdf->controls->move_parallel_y
# define PROJECTION fdf->controls->projection

typedef struct	s_map
{
	int		x;
	int		y;
	int		z;
	double	rotated_x;
	double	rotated_y;
	double	rotated_z;
	
}				t_map;

typedef struct	s_window
{
	int			height;
	int			width;
}				t_window;

typedef struct	s_draw
{
	int			dx;
	int			dy;
	int			slope_y;
	int			slope_x;
	int			decision_var;
}				t_draw;

typedef struct	s_controls
{
	int			projection;
	int			zoom;
	int			change_altitude;
	int			move_parallel_x;
	int			move_parallel_y;
	int			fixed_dx;
	int			fixed_dy;
}				t_controls;


typedef struct	s_fdf
{
	void		*win_ptr;
	void		*mlx_ptr;
	t_draw		*draw;
	t_window	*window;
	t_map		**map;
	t_controls	*controls;
}				t_fdf;

void	draw(t_fdf *fdf);
int		expose_hook(t_fdf *fdf);
void	init(t_fdf *fdf);
void	print_usage(void);
int		mouse_press(int button, int x, int y, t_fdf *fdf);
int		key_press(int key, t_fdf *fdf);
void	perror_exit(char *error);
int		read_from_file(t_fdf *fdf, int ac, char **av);
void	rotate(t_fdf *fdf);

#endif
