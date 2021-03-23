/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:13:23 by jrignell          #+#    #+#             */
/*   Updated: 2021/03/22 19:35:06 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** Includes
*/

# include <sys/ioctl.h>
# include <fcntl.h>
# include "mlx.h"
# include <stdio.h>
# include "libft.h"

typedef struct	s_map
{
	int		height;
	int		x;
	int		y;
	
}				t_map;

int		read_from_file(int ac, char **av);
void	print_usage(void);
void	perror_exit(char *error);

#endif
