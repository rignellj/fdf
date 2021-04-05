/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:57:01 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/02 20:18:35 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_check_malloc(void *ptr)
{
	if (!ptr)
	{
		ft_dprintf(STDERR_FILENO, "Cannot allocate memory\n");
		exit(1);
	}
	return (ptr);
}
