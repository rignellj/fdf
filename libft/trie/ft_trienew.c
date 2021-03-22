/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trienew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 15:54:28 by jrignell          #+#    #+#             */
/*   Updated: 2020/07/30 17:30:19 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie.h"

t_trie	*ft_trienew(t_trie *head, const char *word)
{
	t_trie	*tmp;
	int		i;
	int		alpha;

	tmp = head;
	i = 0;
	while (word[i] != '\0')
	{
		alpha = (int)(word[i]);
		if (tmp->child[alpha] == NULL)
			tmp->child[alpha] = ft_trieadd(word[i]);
		tmp = tmp->child[alpha];
		i++;
	}
	tmp->is_leaf = TRUE;
	return (head);
}
