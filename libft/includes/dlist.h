/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:40:36 by jrignell          #+#    #+#             */
/*   Updated: 2020/12/23 14:46:34 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_H
# define DLIST_H

# include "libft.h"

typedef struct		s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

int					ft_dlstiterif(t_dlist *lst, int (*f)(t_dlist *elem));

t_dlist				*ft_dlstnew(void const *content, size_t content_size);
t_dlist				*ft_dlstmap(t_dlist *lst, t_dlist *(*f)(t_dlist *elem));
t_dlist				*ft_dlstget_first(t_dlist *current);
t_dlist				*ft_dlstget_last(t_dlist *current);

void				ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t));
void				ft_dlstadd(t_dlist **alst, t_dlist *new);
void				ft_dlstiter(t_dlist *lst, void (*f)(t_dlist *elem));
void				ft_dlstappend(t_dlist **alst, t_dlist *new);
void				ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t));
void				ft_dinsert_after(t_dlist **node, t_dlist *new);
void				ft_dinsert_before(t_dlist **node, t_dlist *new);

#endif
