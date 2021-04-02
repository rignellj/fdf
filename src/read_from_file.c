/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:48:50 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/02 10:57:04 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	form_pixel(size_t *x, size_t *y, char *altitude)
{
	t_map	pixel;

	ft_bzero(&pixel, sizeof(t_map));	
	pixel.x = (*x);
	pixel.y = (*y);
	pixel.z = ft_atoi(altitude);
	return (pixel);
}

static void		assign_pixels(size_t *y, char ***array,
				t_map **line, t_fdf *fdf)
{
	size_t			x;
	size_t			pixels_pre_line;
	static int		width;

	if (!width)
		width = MAP_WIDTH;
	if (MAP_WIDTH != width)
		perror_exit(NULL, "Error: Invalid Map");
	x = 0;
	pixels_pre_line = MAP_WIDTH;
	while ((pixels_pre_line)--)
	{
		(*line)[x] = form_pixel(&x, y, (*array)[x]);
		x++;
	}
}

static t_map	**create_map(t_list **head, int *lines, char *tmp, t_fdf *fdf)
{
	t_map	**map;
	t_map	*line;
	char	**array;
	size_t	y;

	y = 0;
	ft_check_malloc(map = (t_map **)ft_memalloc(sizeof(t_map *) * (MAP_HEIGHT + 1)));
	while ((*lines)--)
	{
		tmp = (char *)ft_pop(head);
		ft_check_malloc(array = ft_strsplit(tmp, ' '));
		MAP_WIDTH = ft_strarrlen(array);
		line = (t_map *)ft_memalloc(sizeof(t_map) * MAP_WIDTH + 1);
		ft_check_malloc(line);
		assign_pixels(&y, &array, &line, fdf);
		map[y++] = line;
		ft_arraydel(&array);
		ft_strdel(&tmp);
	}
	return (map);
}

static void loop_gnl(int fd, t_fdf *fdf)
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
		new = ft_lstnew(line, ft_strlen(line) + 1);
		ft_check_malloc(new);
		ft_lstaddend(&head, new);
		lines++;
		ft_strdel(&line);
	}
	if (ret == -1)
		perror_exit("read", NULL);
	MAP_HEIGHT = lines;
	fdf->map = create_map(&head, &lines, line, fdf);
}

int			read_from_file(t_fdf *fdf, int ac, char **av)
{
	int		fd;

	if (ac != 2)
		return (1);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		perror_exit("open", NULL);
	loop_gnl(fd, fdf);
	if (close(fd) == -1)
		perror_exit("close", NULL);
	return (0);
}
