/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:13:23 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/05 13:20:40 by jrignell         ###   ########.fr       */
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

# define WHITE 0xFFFFFFF
# define BLUE 0x0000FF
# define GREEN 0X00FF00
# define MAGENTA 0XFF00FF
# define CYAN 0X00FFFF
# define YELLOW 0xFFFF00
# define ORANGE 0XFFC000
# define RED 0XFF0000
# define CREAM 0XFFF4C2
# define BROWN 0X9C6137
# define SEA_LEVEL 0xFFEDD5

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080
# define PIXELS_TO_MOVE_WITH_ARROW 45

# define RAD63 1.107149
# define RAD45 0.758398
# define RAD30 0.523599
# define RAD15 0.261799

typedef struct s_map
{
	int			x;
	int			y;
	int			z;
	double		rotated_x;
	double		rotated_y;
	double		rotated_z;
}				t_map;

typedef struct s_draw
{
	int			dx;
	int			dy;
	int			slope_y;
	int			slope_x;
	int			decision_var;
}				t_draw;

typedef struct s_controls
{
	int			projection;
	int			zoom;
	int			change_altitude;
	int			move_parallel_x;
	int			move_parallel_y;
	int			fixed_dx;
	int			fixed_dy;
}				t_controls;

typedef struct s_colors
{
	double		sea;
	double		sea1;
	double		sea2;
	double		sea3;
	double		sea4;
	double		sea5;
	double		sea_1;
	double		sea_2;
	double		sea_3;
	double		sea_4;
	double		sea_5;
}				t_colors;

typedef struct s_fdf
{
	void		*win_ptr;
	void		*mlx_ptr;
	int			height;
	int			width;
	t_draw		*draw;
	t_map		**map;
	t_controls	*controls;
	t_colors	*colors;
}				t_fdf;

void			draw(t_fdf *fdf);
void			define_colors(t_fdf *fdf);
int				expose_hook(t_fdf *fdf);
void			init(t_fdf *fdf);
void			print_usage(int ac);
int				mouse_press(int button, int x, int y, t_fdf *fdf);
int				key_press(int key, t_fdf *fdf);
void			perror_exit(char *error, char *message);
void			read_from_file(t_fdf *fdf, int ac, char **av);
void			rotate(t_fdf *fdf);
void			write_into_screen(t_fdf *fdf);

#endif
