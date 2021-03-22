/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:13:46 by ttampio           #+#    #+#             */
/*   Updated: 2021/01/21 12:11:31 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_straddchr(char **str_ptr, char c)
{
	char	*mod_str;
	size_t	str_len;

	if (!str_ptr)
		return (NULL);
	if (!*str_ptr)
	{
		if (!(mod_str = ft_malchr(c)))
			return (NULL);
		*str_ptr = mod_str;
		return (mod_str);
	}
	str_len = ft_strlen(*str_ptr);
	mod_str = (char*)malloc(sizeof(char) * str_len + 2);
	if (!mod_str)
		return (NULL);
	ft_strcpy(mod_str, *str_ptr);
	mod_str[str_len] = c;
	mod_str[str_len + 1] = '\0';
	free(*str_ptr);
	*str_ptr = mod_str;
	return (mod_str);
}
