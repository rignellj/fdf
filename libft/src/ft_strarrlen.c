/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 16:56:02 by ttampio           #+#    #+#             */
/*   Updated: 2020/11/05 15:40:29 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strarrlen(char **strarr)
{
	size_t	i;

	i = 0;
	while (strarr && *strarr++)
		i++;
	return (i);
}
