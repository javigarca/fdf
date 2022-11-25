/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:38:38 by javigarc          #+#    #+#             */
/*   Updated: 2022/11/25 13:57:54 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_countcols(const char *str, char c)
{
	int	i;
	int	newcol;

	i = 0;
	newcol = 0;
	if (str == 0)
		return (0);
	while (*str)
	{
		if (*str != c && newcol == 0)
		{
			newcol = 1;
			i++;
		}
		else if (*str == c)
		{
			newcol = 0;
		}
		str++;
	}
	return (i);
}

t_coord	ft_rows_cols_check(int fd)
{
	int		rows;
	int		colscheck;
	t_coord	coords;
	char	*line;

	line = NULL;
	rows = 0;
	line = get_next_line(fd);
	colscheck = ft_countcols(line, ' ');
	while (line != NULL)
	{
		rows++;
		line = get_next_line(fd);
	}
	coords.rowx = rows;
	coords.coly = colscheck;
	return (coords);
}

void	ft_print_map(t_map maptoprint, int rows, int cols)
{
	int	x;
	int	y;

	x = 0;
	while (x < rows)
	{
		y = 0;
		while (y < cols)
		{
			ft_putnbr_fd(maptoprint.mapdots[x][y].hz, 1);
			ft_putstr_fd("  ", 1);
			y++;
		}
		ft_putstr_fd("\n", 1);
		x++;
	}
}

t_map	ft_read_map(char *namefile)
{
	t_map	maptoload;
	int		fd;

	fd = open(namefile, O_RDWR);
	if (fd > 0)
	{
		maptoload.rowscols = ft_rows_cols_check(fd);
		close(fd);
		fd = open(namefile, O_RDWR);
		maptoload.mapdots = ft_load_mapdots(fd, maptoload.rowscols.rowx, \
				maptoload.rowscols.coly);
	}
	else
	{
		ft_putstr_fd("Error. Invalid file.\n", 2);
		exit(1);
	}
	return (maptoload);
}

t_dot	**ft_load_mapdots(int fd, int rows, int cols)
{
	t_dot	**dotstoload;
	char	**lines;
	int		x;
	int		y;

	x = -1;
	dotstoload = (t_dot **) malloc(sizeof (t_dot *) * rows);
	if (!dotstoload)
		exit(1);
	while (++x < rows)
	{
		dotstoload[x] = (t_dot *) malloc(sizeof (t_dot) * cols);
		if (dotstoload[x] == NULL)
			exit(1);
		lines = ft_split(get_next_line(fd), ' ');
		y = -1;
		while (++y < cols)
		{
			dotstoload[x][y].hz = ft_atoi(lines[y]);
			dotstoload[x][y].dotcolor = DEF_CLR;
		}
		lines = NULL;
	}
	return (dotstoload);
}
