#include "fdf.h"

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
		maptoload.mapdots = ft_load_mapdots(fd, maptoload.rowscols.row, \
				maptoload.rowscols.col);
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
	dotstoload = (t_dot **) malloc(sizeof (t_dot *) * rows + 1);
	if (!dotstoload)
		exit(1);
	while (++x < rows)
	{
		dotstoload[x] = (t_dot *) malloc(sizeof (t_dot) * cols + 1);
		if (dotstoload[x] == NULL)
			exit(1);
		lines = ft_split(get_next_line(fd), ' ');
		y = -1;
		while (++y < cols)
		{
			dotstoload[x][y].h = ft_atoi(lines[y]);
			dotstoload[x][y].dotcolor = 0;
		}
		lines = NULL;
	}
	return (dotstoload);
}

int	main(int argc, char **argv)
{
	t_map		maploaded;

	if (argc == 2)
	{
		maploaded = ft_read_map(argv[1]);
		ft_putstr_fd("\nAHORA EL MAPA\n", 1);
		ft_print_map(maploaded, maploaded.rowscols.row, maploaded.rowscols.col);
	}
	else
		ft_putstr_fd("Type ./fdf <map.fdf>\n", 1);
//	free(maploaded.mapdots);
	return (0);
}
