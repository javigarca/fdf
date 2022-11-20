#include "fdf.h"

void	ft_start_draw(t_fdfdata *fdata)
{
	ft_start_line_row(fdata);
	ft_start_line_col(fdata);
	mlx_clear_window(fdata->mlx, fdata->win);
	mlx_put_image_to_window(fdata->mlx, fdata->win, fdata->img, 100, 0);
	mlx_loop(fdata->mlx);
}

void	ft_start_line_row(t_fdfdata *fdata)
{
	t_coord	begin;
	t_coord	end;
	int rows;
	int cols;

	rows = 0;
	while (rows < fdata->map.rowscols.rowx)
	{
		cols = 0;
		while (cols < fdata->map.rowscols.coly - 1)
		{
			begin = isopro(rows,cols,fdata->map.mapdots[rows][cols].hz);
			end = isopro(rows,cols + 1,fdata->map.mapdots[rows][cols + 1].hz);
			ft_draw_line(fdata, begin, end);
			cols++;
		}
		rows++;
	}
}

void	ft_start_line_col(t_fdfdata *fdata)
{
	t_coord	begin;
	t_coord	end;
	int rows;
	int cols;

	cols = 0;
	while (cols < fdata->map.rowscols.coly)
	{
		rows = 0;
		while (rows < fdata->map.rowscols.rowx - 1)
		{
			begin = isopro(rows,cols,fdata->map.mapdots[rows][cols].hz);
			end = isopro(rows + 1,cols,fdata->map.mapdots[rows + 1][cols].hz);
			ft_draw_line(fdata, begin, end);
			rows++;
		}
		cols++;
	}
}

void	ft_draw_line(t_fdfdata *fdata, t_coord begin, t_coord end)
{
	printf("%i", fdata->hookmods.angle);
	ft_putstr_fd("\n Ahora COORD a iso \n", 1);
	printf("Begin:%d - %d\n", begin.rowx, begin.coly);
	printf("End:%d - %d\n", end.rowx, end.coly);

}
