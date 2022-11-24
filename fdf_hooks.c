#include "fdf.h"

int	ft_button_close(t_fdfdata *fdata)
{
//	free(fdata->map.mapdots);
	fdata = NULL;
//	system ("leaks fdf");
	exit(0);
	return (0);
}

void	ft_scale(int key, t_fdfdata *fdata)
{
	if (key == 69 || key == 24 || key == 4)
	{
		fdata->hookmods.scale++;
	}
	else if (key == 78 || key == 27 || key == 5)
		fdata->hookmods.scale--;
	if (fdata->hookmods.scale < 1)
		fdata->hookmods.scale = 1;
	ft_start_draw(fdata);
}

void	ft_axis_displ(int key, t_fdfdata *fdata)
{
	if (key == 123)
		fdata->hookmods.xdispl -= 10;
	else if (key == 124)
		fdata->hookmods.xdispl += 10;
	else if (key == 125)
		fdata->hookmods.ydispl += 10;
	else
		fdata->hookmods.ydispl -= 10;
	ft_start_draw(fdata);
}

void	ft_rotate_view(int key, t_fdfdata *fdata)
{
	if (key == 14)
		fdata->hookmods.z_angle += 0.05;
	if (key == 2)
		fdata->hookmods.z_angle -= 0.05;
	if (key == 12)
		fdata->hookmods.x_angle -= 0.05;
	if (key == 0)
		fdata->hookmods.x_angle += 0.05;
	if (key == 13)
		fdata->hookmods.y_angle += 0.05;
	if (key == 1)
		fdata->hookmods.y_angle -= 0.05;
	ft_start_draw(fdata);
}
/*

   ** Change z value. Make map more flatten
  
void	flatten(int key, t_fdf *fdf)
{
		if (key == MAIN_PAD_LESS)
					fdf->camera->z_divisor -= 0.1;
			else if (key == MAIN_PAD_MORE)
						fdf->camera->z_divisor += 0.1;
				if (fdf->camera->z_divisor < 0.1)
							fdf->camera->z_divisor = 0.1;
					else if (fdf->camera->z_divisor > 10)
								fdf->camera->z_divisor = 10;
						draw(fdf->map, fdf);
}

   ** Change projection type
*/ 
void	ft_change_view(int key, t_fdfdata *fdata)
{
	if (key == 35)
	{
		fdata->hookmods.x_angle = 0;
		fdata->hookmods.y_angle = 0;
		fdata->hookmods.z_angle = 0;
		if (fdata->hookmods.view)
			fdata->hookmods.view = 0;
		else
			fdata->hookmods.view++;
	}
	ft_start_draw(fdata);
}
