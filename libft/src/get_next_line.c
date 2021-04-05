/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:57:54 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/03 13:27:52 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	check_buf_trim_line(char **str, char **line, int ret, int fd)
{
	int		len;
	char	*tmp;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		++len;
	if (str[fd][len] == '\n')
	{
		*line = ft_strsub(str[fd], 0, len);
		tmp = ft_strdup(str[fd] + len + 1);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

static int	init_and_check(int fd, char ***line, int *ret)
{
	if (fd < 0 || !*line)
		return (-1);
	*ret = 1;
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*tmp;
	static char	*str[FD_SIZE];

	if (init_and_check(fd, &line, &ret))
		return (-1);
	while (ret > 0)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret <= 0)
			break ;
		buf[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		tmp = ft_strjoinfree(str[fd], buf, FREE_LEFT);
		str[fd] = tmp;
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (check_buf_trim_line(str, line, ret, fd));
}
