/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:15:07 by jrignell          #+#    #+#             */
/*   Updated: 2021/03/22 16:05:33 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	deal_key(int key, void *param)
// {
// 	(void)param;
// 	(void)key;
// 	ft_putchar('X');
// 	return (0);
// }

int			main(int ac, char **av)
{
	// void	*mlx_ptr;
	// void	*win_ptr;
	int		ret;

	if ((ret = read_from_file(ac, av)))
		print_usage();
	// mlx_ptr = mlx_init();
	// win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	// mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	// mlx_key_hook(win_ptr, deal_key, (void*)0);
	// mlx_loop(mlx_ptr);
	return (0);
}
