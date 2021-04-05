/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:48:50 by jrignell          #+#    #+#             */
/*   Updated: 2021/04/05 13:32:17 by jrignell         ###   ########.fr       */
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

static void	assign_pixels(size_t *y, char ***array, t_map **line, t_fdf *fdf)
{
	size_t		x;
	size_t		pixels_pre_line;
	static int	width;

	if (!width)
		width = fdf->width;
	if (fdf->width != width)
		perror_exit(NULL, "fdf: syntax error: Invalid Map");
	x = 0;
	pixels_pre_line = fdf->width;
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
	map = (t_map **)ft_memalloc(sizeof(t_map *) * (fdf->height + 1));
	ft_check_malloc(map);
	while ((*lines)--)
	{
		tmp = (char *)ft_pop(head);
		array = ft_strsplit(tmp, ' ');
		ft_check_malloc(array);
		fdf->width = ft_strarrlen(array);
		line = (t_map *)ft_memalloc(sizeof(t_map) * fdf->width + 1);
		ft_check_malloc(line);
		assign_pixels(&y, &array, &line, fdf);
		map[y++] = line;
		ft_arraydel(&array);
		ft_strdel(&tmp);
	}
	return (map);
}

static void	loop_gnl(int fd, t_fdf *fdf)
{
	char	*line;
	int		ret;
	int		lines;
	t_list	*new;
	t_list	*head;

	head = NULL;
	lines = 0;
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret == 0 || ret == -1)
			break ;
		new = ft_lstnew(line, ft_strlen(line) + 1);
		ft_check_malloc(new);
		ft_lstaddend(&head, new);
		lines++;
		ft_strdel(&line);
	}
	if (ret == -1)
		perror_exit("fdf: read", NULL);
	fdf->height = lines;
	fdf->map = create_map(&head, &lines, line, fdf);
}

void	read_from_file(t_fdf *fdf, int ac, char **av)
{
	int	fd;

	if (ac < 2)
		print_usage(0);
	else if (ac > 2)
		print_usage(1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		perror_exit("fdf: open", NULL);
	loop_gnl(fd, fdf);
	if (close(fd) == -1)
		perror_exit("fdf: close", NULL);
}
