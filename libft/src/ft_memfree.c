/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 18:38:15 by ttampio           #+#    #+#             */
/*   Updated: 2020/01/14 10:59:25 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  Frees array of pointers. Length must be provided as second argument.
*/

void	ft_memfree(void **mem, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
		free(mem[i++]);
	free(mem);
}
