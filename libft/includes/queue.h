/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 19:23:52 by jrignell          #+#    #+#             */
/*   Updated: 2021/02/05 14:23:12 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "libft.h"
# include <unistd.h>

typedef struct s_list	t_list;

t_list	*queue_new(const void *data, size_t content_size);
t_list	*queue_push(t_list **head, const void *data, size_t size);

#endif
