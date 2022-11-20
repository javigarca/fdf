#include "fdf.h"

t_coord isopro(t_fdfdata *fdata, int x, int y, int z)
{
	t_coord isocoord;
	int angle;
	int scale;

	angle = fdata->hookmods.angle;
	scale = fdata->hookmods.scale;
	x *= scale;
	y *= scale;
	z *= scale;
	x -= fdata->map.rowscols.rowx * scale / 2;
	y -= fdata->map.rowscols.coly * scale / 2;
	isocoord.rowx = (x - y) * cos(rad(angle));
	isocoord.coly = - z + (x + y) * sin(rad(angle));
	return (isocoord);
}

t_coord parpro(int x, int y, int z)
{
	t_coord parcoord;
	int angle;

	angle = 30;
	parcoord.rowx = x * cos(rad(angle)) + y;
	parcoord.coly = x * sin(rad(angle)) - z;
	return (parcoord);
// repensar
}

double	rad(int deg)
{
	return (deg * 3.14159265F / 180.0F);
}

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
