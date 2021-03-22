/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trie_haschild_tovisit.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 09:59:16 by jrignell          #+#    #+#             */
/*   Updated: 2020/07/29 13:20:11 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie.h"

int		ft_trie_haschild_tovisit(t_trie *node)
{
	unsigned char	i;

	if (!node)
		return (-2);
	i = 0;
	while (i < ASCII)
	{
		if (node->child[i] && node->child[i]->visited == FALSE)
			return (i);
		i++;
	}
	return (-1);
}
