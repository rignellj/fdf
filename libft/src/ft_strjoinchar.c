/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 11:37:28 by jrignell          #+#    #+#             */
/*   Updated: 2020/07/24 12:59:53 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinchar(char const *s1, char c)
{
	size_t	i;
	char	*new;

	i = 0;
	new = ft_strnew(ft_strlen(s1) + 1);
	if (new == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = c;
	return (new);
}
