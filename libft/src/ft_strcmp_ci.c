/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_ci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 10:33:23 by ttampio           #+#    #+#             */
/*   Updated: 2020/08/18 17:12:59 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp_ci(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	us1 = (unsigned char*)s1;
	us2 = (unsigned char*)s2;
	while (us1[i] && us2[i])
	{
		if (ft_isupper(us1[i]) && \
			!(us1[i] == us2[i] || us1[i] + 32 == us2[i]))
			return (us1[i] != us2[i]);
		else if (ft_islower(us1[i]) && \
			!(us1[i] == us2[i] || us1[i] - 32 == us2[i]))
			return (us1[i] != us2[i]);
		else if (!ft_isalpha(us1[i]) && us1[i] != us2[i])
			return (us1[i] != us2[i]);
		i++;
	}
	if ((us2[i]) || us1[i])
		return (us1[i] != us2[i]);
	return (0);
}
