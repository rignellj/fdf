/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joindel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 20:05:17 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/03 18:37:03 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joindel(char *s1, char *s2)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	new = ft_strjoin(s1, s2);
	if (!new)
		return (NULL);
	ft_memdel((void **)&s1);
	ft_memdel((void **)&s2);
	return (new);
}
