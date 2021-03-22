/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trieiter_function.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:40:03 by jrignell          #+#    #+#             */
/*   Updated: 2021/02/05 14:20:38 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie.h"

t_trie	*ft_trieiter_function(t_trie *trie, const char *word,
		void (*f)(t_trie *elem))
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
		f(ptr);
		ptr = ptr->child[alpha];
		i++;
	}
	if (word[i] == '\0')
		return (ptr);
	return (NULL);
}
