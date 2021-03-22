/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 15:56:28 by ttampio           #+#    #+#             */
/*   Updated: 2020/07/11 16:22:55 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strarrfree(char ***strarr)
{
	size_t	i;

	if (!*strarr)
		return ;
	i = 0;
	while ((*strarr)[i])
	{
		free((*strarr)[i]);
		i++;
	}
	free(*strarr);
	*strarr = NULL;
}
