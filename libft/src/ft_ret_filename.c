/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ret_filename.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 20:59:48 by ttampio           #+#    #+#             */
/*   Updated: 2020/12/15 22:54:48 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ret_filename(char *file_str)
{
	char *filename_pos;

	if (!(filename_pos = ft_strrchr(file_str, '/')))
		return (file_str);
	else if (*(filename_pos + 1))
		return (filename_pos + 1);
	return (file_str);
}
