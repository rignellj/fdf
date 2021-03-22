/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triedel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:20:14 by jrignell          #+#    #+#             */
/*   Updated: 2020/07/22 21:30:42 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie.h"

void	ft_triedel(t_trie *node)
{
	short	i;

	i = 0;
	while (i < ASCII)
	{
		if (node->child[i] != NULL)
			ft_triedel(node->child[i]);
		else
			i++;
	}
	ft_memdel((void **)&node);
}
