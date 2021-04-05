/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:50:57 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/02 20:13:12 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	perror_exit(char *error, char *message)
{
	if (!message)
		perror(error);
	else
		ft_dprintf(STDERR_FILENO, "%s\n", message);
	exit(1);
}
