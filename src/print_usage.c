/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:59:48 by jrignell          #+#    #+#             */
/*   Updated: 2021/03/22 18:45:46 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_usage(void)
{
	ft_dprintf(STDERR_FILENO, "usage: ./fdf <file_to_read_from>\n");
	exit(1);
}
