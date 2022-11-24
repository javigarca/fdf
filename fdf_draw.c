#include "fdf.h"

void	ft_start_hooks(t_fdfdata *fdata)
{
//	mlx_key_hook(fdata->win, &key_close, &fdata);
	mlx_hook(fdata->win, 2, 0, ft_key_press, fdata);
//	mlx_hook(fdata->win, 4, 0, mouse_press, fdf);
//	mlx_hook(fdata->win, 5, 0, mouse_release, fdf);
//	mlx_hook(fdata->win, 6, 0, mouse_move, fdf);
	mlx_hook(fdata->win, 17, 0, ft_button_close, fdata);
}
void	ft_start_draw(t_fdfdata *fdata)
{
	ft_clear_image(fdata, BKG_CLR_A, BKG_CLR_B);
	ft_start_line_row(fdata);
	ft_start_line_col(fdata);
//	ft_draw_menu(fdata);
	mlx_put_image_to_window(fdata->mlx, fdata->win, fdata->img, 320, 0);
//	ft_start_hooks(fdata);
//	mlx_loop(fdata->mlx);
}

void	ft_start_line_row(t_fdfdata *fdata)
{
	t_coord	begin;
	t_coord	end;
	int		rows;
	int		cols;

	rows = 0;
	while (rows < fdata->map.rowscols.rowx)
	{
		cols = 0;
		while (cols < (fdata->map.rowscols.coly -1))
		{
			begin = ft_iso(fdata, rows, cols, fdata->map.mapdots[rows][cols].hz);
			end = ft_iso(fdata, rows, cols + 1, fdata->map.mapdots[rows][cols + 1].hz);
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
	int		rows;
	int		cols;

	cols = 0;
	while (cols < fdata->map.rowscols.coly)
	{
		rows = 0;
		while (rows < (fdata->map.rowscols.rowx - 1))
		{
			begin = ft_iso(fdata, rows, cols, fdata->map.mapdots[rows][cols].hz);
			end = ft_iso(fdata, rows + 1, cols, fdata->map.mapdots[rows + 1][cols].hz);
			ft_draw_line(fdata, end, begin);
			rows++;
		}
		cols++;
	}
}

void	ft_draw_line(t_fdfdata *fdata, t_coord begin, t_coord end)
{
//	printf("%i ", fdata->hookmods.angle);
//	ft_putstr_fd("\n Ahora COORD a iso \n", 1);
//	printf("Begin:%d - %d\n", begin.rowx, begin.coly);
//	printf("End:%d - %d\n", end.rowx, end.coly);
	

	t_coord	delta;
	t_coord	sign;
	t_coord	cur;
	int		error[2];

	delta.rowx = FT_ABS(end.rowx - begin.rowx);
//	printf("row done");
	delta.coly = FT_ABS(end.coly - begin.coly);
//	printf("col done");
	sign.rowx = begin.rowx < end.rowx ? 1 : -1;
//	printf("sin row done");
	sign.coly = begin.coly < end.coly ? 1 : -1;
//	printf("sin col  done");
	error[0] = delta.rowx - delta.coly;
//	printf("error done");
	cur = begin;
//	printf("curr done");
	while (cur.rowx != end.rowx || cur.coly != end.coly)
	{
		ft_light_my_pixel(fdata, cur.rowx, cur.coly, DEF_CLR);
	//	put_pixel(fdf, cur.x, cur.y, get_color(cur, f, s, delta));
		if ((error[1] = error[0] * 2) > -delta.coly)
		{
			error[0] -= delta.coly;
			cur.rowx += sign.rowx;
		}
		if (error[1] < delta.rowx)
		{
			error[0] += delta.rowx;
			cur.coly += sign.coly;
		}
	}
}

	/*
// 0 - Distancias que se desplazan en cada eje
	t_bresnum	bn;
	
	bn.dY = (end.coly - begin.coly);
	bn.dX = (end.rowx - begin.rowx);
	
	// 1 - Incrementos para las secciones con avance inclinado
    if (bn.dY >= 0)
		bn.IncYi = 1;
	else
	{
		bn.dY = -bn.dY;
		bn.IncYi = -1;
	}
	if (bn.dX >= 0)
		bn.IncXi = 1;
	else
	{
		bn.dX = -bn.dX;
		bn.IncXi = -1;
	}
    // 2 - Incrementos para las secciones con avance recto:
    if (bn.dX >= bn.dY)
	{
		bn.IncYr = 0;
		bn.IncXr = bn.IncXi;
	}
	else
	{
		bn.IncXr = 0;
		bn.IncYr = bn.IncYi;
	// Cuando dy es mayor que dx, se intercambian, para reutilizar el mismo bucle.
		ft_swap(&bn.dX, &bn.dY);
	}
    // 3  - Inicializar valores (y de error).
	bn.X = begin.rowx;
	bn.Y = begin.coly;
    bn.avR = (2 * bn.dY);
    bn.av = (bn.avR - bn.dX);
    bn.avI = (bn.av - bn.dX);
    // Pinto el primer pixel.
//	ft_light_my_pixel(fdata, bn.X, bn.Y, DEF_CLR);
    // 4  - Bucle para el trazado de las línea.
    while (bn.X < end.rowx) 
	{
		ft_light_my_pixel(fdata, bn.X, bn.Y, DEF_CLR);
 //       printf("(%i, %i)\n", bn.X, bn.Y);
  //          Mensaje(av + " ") // (debug) para ver los valores de error global que van apareciendo.
		if (bn.av >= 0)
		{
			bn.X = (bn.X + bn.IncXi);     // X aumenta en inclinado.
            bn.Y = (bn.Y + bn.IncYi);     // Y aumenta en inclinado.
            bn.av = (bn.av + bn.avI);	// Avance Inclinado
		}
		else
		{
			bn.X = (bn.X + bn.IncXr);     // X aumenta en recto.
            bn.Y = (bn.Y + bn.IncYr);     // Y aumenta en recto.
            bn.av = (bn.av + bn.avR);     // Avance Recto
		}
//		ft_light_my_pixel(fdata, bn.X, bn.Y, DEF_CLR);
	}
//		ft_light_my_pixel(fdata, bn.X, bn.Y, DEF_CLR);
//	printf("FIN CALCULOS");
}*/
