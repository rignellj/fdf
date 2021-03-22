/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 13:22:00 by jrignell          #+#    #+#             */
/*   Updated: 2020/08/16 13:33:30 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int num, int power)
{
	if (power < 0 || num == 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (power == 1)
		return (num);
	else
		return (num * ft_power(num, power - 1));
}
