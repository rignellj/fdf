/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triesearch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:50:54 by jrignell          #+#    #+#             */
/*   Updated: 2020/07/23 20:27:14 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie.h"

int		ft_triesearch(t_trie **head, const char *word)
{
	t_trie	*tmp;
	int		i;
	int		alpha;

	tmp = *head;
	i = 0;
	while (word[i] != '\0')
	{
		alpha = (int)word[i];
		if (tmp->child[alpha] == NULL)
			return (0);
		tmp = tmp->child[alpha];
		i++;
	}
	if (tmp && tmp->is_leaf == TRUE)
		return (1);
	return (0);
}
