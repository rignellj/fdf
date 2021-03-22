/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 19:26:52 by jrignell          #+#    #+#             */
/*   Updated: 2020/12/20 14:41:13 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_list	*queue_new(const void *data, size_t content_size)
{
	return (ft_stacknew(data, content_size));
}
