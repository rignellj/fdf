/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:07:12 by jrignell          #+#    #+#             */
/*   Updated: 2020/12/21 16:52:01 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t))
{
	if ((*alst)->next)
		ft_dlstdel(&(*alst)->next, del);
	ft_dlstdelone(&(*alst), del);
}
