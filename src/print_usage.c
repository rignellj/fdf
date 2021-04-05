/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:59:48 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/05 13:33:52 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_usage(int ac)
{
	if (ac)
		ft_dprintf(STDERR_FILENO, "fdf: Too many arguments\n");
	else
		ft_dprintf(STDERR_FILENO, "fdf: Give input file\n");
	ft_dprintf(STDERR_FILENO, "fdf: usage: ./fdf <input_file_to_read_from>\n");
	exit(1);
}
