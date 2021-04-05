/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:02:50 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/03 13:52:23 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"

typedef struct s_list	t_list;

void	*ft_pop(t_list **head);
int		ft_isempty(t_list *head);

#endif
