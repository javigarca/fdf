#include "fdf.h"

t_coord	ft_cal_pro(t_fdfdata *fdata, int x, int y, int z)
{
	t_coord	coord;
	int		angle;
	int		scale;

	angle = fdata->hookmods.angle;
	scale = fdata->hookmods.scale;
	x *= scale;
	y *= scale;
	z *= scale;
//	printf("x:%i y:%i z:%i", x, y, z);
//	printf("angle:%i", angle);
//	printf("X angle:%f", fdata->hookmods.x_angle);
//	printf("*Y angle:%f", fdata->hookmods.y_angle);
//	printf("*Z angle:%f\r", fdata->hookmods.z_angle);
	ft_rotate_x_axis(&y, &z, fdata->hookmods.x_angle);
	ft_rotate_y_axis(&x, &z, fdata->hookmods.y_angle);
	ft_rotate_z_axis(&x, &y, fdata->hookmods.z_angle);
//	printf("x:%i y:%i z:%i\n", x, y, z);
//	printf("view=%i", fdata->hookmods.view);
	if (fdata->hookmods.view != 0)
	{
		coord.rowx = (x - y) *  -cos(rad(angle));
		coord.coly = -z + (x + y) * sin(rad(angle));
	}
	else
	{
		angle = 15;
//		coord.rowx = x * cos(rad(360)) + y;
//		coord.coly = x * sin(rad(360)) - z;
//		coord.rowx = x;
//		coord.coly = y;
		coord.rowx = (x - y) *  -cos(rad(angle));
		angle = 60;
		coord.coly = (x + y) * sin(rad(angle));
	}
//	printf("angle:%i coordX:%i coordY:%i\n", angle, coord.rowx, coord.coly);
	coord.rowx += (fdata->img_size.rowx / 2) + fdata->hookmods.xdispl;
	coord.coly += ((fdata->img_size.coly - fdata->map.rowscols.coly) / 2) + fdata->hookmods.ydispl;
	return (coord);
}

double	rad(int deg)
{
	return (deg * 3.14159265F / 180.0F);
}

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}
