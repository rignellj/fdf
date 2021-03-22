/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:28:09 by ttampio           #+#    #+#             */
/*   Updated: 2019/12/05 17:45:00 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_reval(int num, int uppr_case)
{
	if (num >= 0 && num <= 9)
		return (char)(num + '0');
	else if (uppr_case)
		return (char)(num - 10 + 'A');
	else
		return (char)(num - 10 + 'a');
}

/*
** Converts an unsigned long long into other base (starting with base 2).
*/

char		*ft_dec_to_base(int base, unsigned long long input_num, \
							int uppr_case)
{
	char	*res;
	int		i;

	if (base < 2)
		return (NULL);
	else if (input_num == 0)
		return (ft_strdup("0"));
	res = malloc(sizeof(char) * 100);
	i = 0;
	while (input_num > 0)
	{
		res[i] = ft_reval(input_num % base, uppr_case);
		input_num = input_num / base;
		i++;
	}
	res[i] = '\0';
	ft_strrev(res);
	return (res);
}
