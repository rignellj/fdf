/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triematch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 17:29:02 by jrignell          #+#    #+#             */
/*   Updated: 2021/03/23 12:33:47 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie.h"

static char	*init_last_char(char *data)
{
	size_t	last_char;

	if (data)
	{
		last_char = ft_strlen(data);
		last_char -= (last_char == 0) ? 0 : 1;
		data[last_char] = '\0';
	}
	return (data);
}

static void	alloc_strs(char *prefix, char ***array, char **suffix[2],
			t_trie *node)
{
	char	*tmp;
	char	**ptr;

	ptr = *array;
	if (!(tmp = ft_strjoin(prefix, (*suffix)[1])))
		return ;
	if (!(*array = ft_array_push(*array, tmp, 0)))
		return ;
	ft_arraydel(&ptr);
	(*suffix)[1] = init_last_char((*suffix)[1]);
	ft_strdel(&tmp);
	node->visited = TRUE;
}

static void	there_is_match(t_trie *node, t_list *head, char ***data,
			char ***array)
{
	int			child_i;
	char		*join;

	if (node && node->is_leaf == TRUE && ft_trie_haschild_tovisit(node) == -1)
	{
		alloc_strs((*data)[0], array, data, node);
		if (!head)
			return ;
		return (there_is_match((t_trie *)ft_pop(&head), head, data, array));
	}
	else if ((child_i = ft_trie_haschild_tovisit(node)) == -1)
	{
		(*data)[1] = init_last_char((*data)[1]);
		node->visited = TRUE;
		if (!head)
			return ;
		return (there_is_match((t_trie *)ft_pop(&head), head, data, array));
	}
	head = (head == NULL) ? ft_stacknew(node, sizeof(t_trie)) :
	ft_stackpush(&head, node, sizeof(t_trie));
	if (!(join = ft_strjoinchar((*data)[1], (char)child_i)))
		return ;
	ft_strdel(&((*data)[1]));
	(*data)[1] = join;
	there_is_match(node->child[child_i], head, data, array);
}

char		**ft_triematch(t_trie **head, const char *word)
{
	t_trie	*tmp;
	char	**ret_array;
	char	**words;

	tmp = ft_trieiter(*head, word);
	if (tmp != NULL)
	{
		if (!(words = ft_arraynew(2)))
			return (NULL);
		if (!(words[0] = ft_strdup(word)))
			return (NULL);
		ret_array = NULL;
		there_is_match(tmp, NULL, &words, &ret_array);
		return (ret_array);
	}
	return (NULL);
}
