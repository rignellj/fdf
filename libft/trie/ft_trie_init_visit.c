/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trie_init_visit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 18:26:02 by jrignell          #+#    #+#             */
/*   Updated: 2021/02/05 14:15:14 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie.h"

void	ft_trie_init_visit(t_trie *node)
{
	size_t	i;
	t_trie	*ptr;

	i = 0;
	ptr = node;
	ptr->visited = FALSE;
	if (ptr->is_leaf == TRUE && (i = ft_trie_haschild_tovisit(ptr)) == -1)
		return ;
	while (i < ASCII)
	{
		if (ptr->child[i])
		{
			ft_trie_init_visit(ptr->child[i]);
		}
		i++;
	}
}
