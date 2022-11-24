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
//	if (fdata->hookmods.view != 0)
//	{
		coord.rowx = (x - y) *  -cos(rad(angle));
		coord.coly = -z + (x + y) * sin(rad(angle));
//	}
//	else
//	{
//		coord.rowx = x * cos(rad(angle)) + y;
//		coord.coly = x * sin(rad(angle)) - z;
//	}
	printf("isox:%i isoy:%i", coord.rowx, coord.coly);
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
