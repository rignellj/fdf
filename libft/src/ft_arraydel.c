/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:37:26 by jrignell          #+#    #+#             */
/*   Updated: 2020/12/16 13:37:30 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arraydel(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
		ft_strdel(&array[i++]);
	if (array != NULL)
	{
		free(array);
		array = NULL;
	}
}
