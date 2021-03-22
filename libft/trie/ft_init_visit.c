/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_visit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:45:30 by jrignell          #+#    #+#             */
/*   Updated: 2020/08/05 16:49:04 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie.h"

void	ft_init_visit(t_trie *elem)
{
	short	i;

	i = 0;
	while (i < ASCII)
	{
		if (elem->child[i])
			elem->child[i]->visited = FALSE;
		i++;
	}
}
