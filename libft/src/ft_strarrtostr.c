/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrtostr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 16:52:24 by ttampio           #+#    #+#             */
/*   Updated: 2020/08/18 17:09:45 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_comb_strlen(char **strarr)
{
	size_t i;
	size_t comb_strlen;

	i = -1;
	comb_strlen = 0;
	while (strarr[++i])
		comb_strlen += ft_strlen(strarr[i]);
	return (comb_strlen);
}

char			*ft_strarrtostr(char **strarr, int free_arr)
{
	size_t	s;
	size_t	c;
	size_t	new_c;
	size_t	comb_strlen;
	char	*new_str;

	if (!strarr)
		return (NULL);
	comb_strlen = count_comb_strlen(strarr);
	if (!(new_str = (char *)malloc(sizeof(char) * (comb_strlen + 1))))
		return (NULL);
	s = -1;
	new_c = 0;
	while (strarr[++s])
	{
		c = -1;
		while (strarr[s][++c])
			new_str[new_c++] = strarr[s][c];
	}
	new_str[new_c] = '\0';
	free_arr ? ft_strarrfree(&strarr) : 0;
	return (new_str);
}
