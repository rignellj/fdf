/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trieiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:33:56 by jrignell          #+#    #+#             */
/*   Updated: 2020/08/05 13:46:11 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie.h"

t_trie	*ft_trieiter(t_trie *trie, const char *word)
{
	t_trie	*ptr;
	size_t	i;
	size_t	alpha;

	ptr = trie;
	i = 0;
	while (word[i] != '\0')
	{
		alpha = (size_t)word[i];
		if (ptr->child[alpha] == NULL)
			return (NULL);
		ptr = ptr->child[alpha];
		i++;
	}
	if (word[i] == '\0')
		return (ptr);
	return (NULL);
}
