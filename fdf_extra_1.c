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
		if (colscheck != ft_countcols(line, ' ') && (line != NULL))
		{
			ft_putstr_fd("Error. Not a valid map.\n", 2);
			exit(1);
		}
	}
	coords.row = rows;
	coords.col = colscheck;
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
			ft_putnbr_fd(maptoprint.mapdots[x][y].h, 1);
			ft_putstr_fd("  ", 1);
			y++;
		}
		ft_putstr_fd("\n", 1);
		x++;
	}
}
