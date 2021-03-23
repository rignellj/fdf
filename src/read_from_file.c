/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:48:50 by jrignell          #+#    #+#             */
/*   Updated: 2021/03/23 12:55:28 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	form_pixel(size_t *x, size_t *y, char *height)
{
	t_map	pixel;
	
	ft_bzero(&pixel, sizeof(t_map));
	pixel.x = *x;
	pixel.y = *y;
	pixel.height = ft_atoi(height);
	return (pixel);
}

static void		assign_pixels(size_t *y, char ***array,
				size_t *pixels_pre_line, t_map **line)
{
	size_t	x;

	x = 0;
	while ((*pixels_pre_line)--)
	{
		(*line)[x] = form_pixel(&x, y, (*array)[x]);
		x++;
	}
}

static t_map	**create_map(t_list **head, int lines, char *tmp)
{
	t_map	**map;
	t_map	*line;
	char	**array;
	size_t	y;
	size_t	pixels_pre_line;

	y = 0;
	ft_check_malloc(map = (t_map **)ft_memalloc(sizeof(t_map *) * (lines + 1)));
	while (lines--)
	{
		tmp = (char *)ft_pop(head);
		ft_check_malloc(array = ft_strsplit(tmp, ' '));
		pixels_pre_line = ft_strarrlen(array);
		line = (t_map *)ft_memalloc(sizeof(t_map) * pixels_pre_line + 1);
		ft_check_malloc(line);
		assign_pixels(&y, &array, &pixels_pre_line, &line);
		map[y++] = line;
		ft_arraydel(&array);
		ft_strdel(&tmp);
	}
	return (map);
}

static t_map	**loop_gnl(int fd)
{
	char	*line;
	int		ret;
	int		lines;
	t_list	*new;
	t_list	*head;

	head = NULL;
	lines = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		new = ft_lstnew(line, sizeof(char *) * ft_strlen(line));
		ft_lstaddend(&head, new);
		lines++;
		ft_strdel(&line);
	}
	if (ret == -1)
		perror_exit("read");
	return (create_map(&head, --lines, line));
}

int			read_from_file(int ac, char **av)
{
	int		fd;
	t_map	**map;

	if (ac != 2)
		return (1);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		perror_exit("open");
	map = loop_gnl(fd);
	if (close(fd) == -1)
		perror_exit("close");
	return (0);
}
