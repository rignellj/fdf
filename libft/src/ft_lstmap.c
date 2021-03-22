/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 09:00:39 by ttampio           #+#    #+#             */
/*   Updated: 2020/08/15 17:20:53 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*new_lst;

	new_lst = NULL;
	while (lst)
	{
		ft_lstaddend(&new_lst, f(lst));
		lst = lst->next;
	}
	return (new_lst);
}
