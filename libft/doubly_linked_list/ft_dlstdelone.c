/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:56:11 by jrignell          #+#    #+#             */
/*   Updated: 2021/01/25 16:58:29 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"
#include <stdlib.h>

void	ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
