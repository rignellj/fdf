/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:15:28 by jrignell          #+#    #+#             */
/*   Updated: 2020/12/23 14:12:47 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dlstadd(t_dlist **alst, t_dlist *new)
{
	new->next = (*alst);
	new->prev = NULL;
	if ((*alst) != NULL)
		(*alst)->prev = new;
	(*alst) = new;
}
