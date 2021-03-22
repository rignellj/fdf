/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:02:50 by jrignell          #+#    #+#             */
/*   Updated: 2021/02/05 14:18:01 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"
# include <unistd.h>

typedef struct s_list	t_list;

int		ft_isempty(t_list *head);

t_list	*ft_stacknew(const void *data, size_t content_size);
t_list	*ft_stackpush(t_list **head, const void *data, size_t size);
t_list	*ft_stackadd(t_list **head, const void *data, size_t size);

void	*ft_peek(t_list *head);
void	*ft_pop(t_list **head);

int		ft_stacksize(t_list **head, int exceed);

#endif
