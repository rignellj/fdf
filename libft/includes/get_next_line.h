/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 17:01:02 by ttampio           #+#    #+#             */
/*   Updated: 2020/08/18 17:01:12 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE  32

typedef struct	s_fd
{
	int			fd_id;
	size_t		i;
	char		*res_str;
}				t_fd;

int				get_next_line(const int fd, char **line);

#endif
