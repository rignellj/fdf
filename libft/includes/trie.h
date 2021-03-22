/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:21:00 by jrignell          #+#    #+#             */
/*   Updated: 2021/02/05 14:22:59 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIE_H
# define TRIE_H
# define ASCII 128

# include "libft.h"

typedef struct		s_trie
{
	char			data;
	struct s_trie	*child[ASCII];
	int				is_leaf;
	int				visited;
}					t_trie;

void				ft_triedel(t_trie *node);
void				ft_trie_init_visit(t_trie *node);
void				ft_init_visit(t_trie *elem);

int					ft_triesearch(t_trie **head, const char *word);
int					ft_trie_haschild_tovisit(t_trie *node);

char				**ft_triematch(t_trie **head, const char *word);

t_trie				*ft_trienew(t_trie *head, const char *word);
t_trie				*ft_trieadd(char data);
t_trie				*ft_trieiter_function(t_trie *trie, const char *word,
					void (*f)(t_trie *elem));
t_trie				*ft_trieiter(t_trie *trie, const char *word);

#endif
