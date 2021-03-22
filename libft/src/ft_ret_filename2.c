/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ret_filename2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:54:36 by ttampio           #+#    #+#             */
/*   Updated: 2020/12/15 22:54:48 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ret_filename2(char *file_str)
{
	char *filename_pos;

	if (!(filename_pos = ft_strrchr(file_str, '/')))
		return (file_str);
	else
		return (filename_pos + 1);
}
