/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trieadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 14:11:56 by jrignell          #+#    #+#             */
/*   Updated: 2020/07/30 17:50:12 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie.h"

t_trie	*ft_trieadd(char data)
{
	t_trie	*new_node;
	int		i;

	if (!(new_node = (t_trie *)ft_memalloc(sizeof(t_trie))))
		return (NULL);
	i = 0;
	while (i < ASCII)
		new_node->child[i++] = NULL;
	new_node->data = data;
	return (new_node);
}
