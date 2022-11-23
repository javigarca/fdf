#include "fdf.h"

t_coord	ft_iso(t_fdfdata *fdata, int x, int y, int z)
{
	t_coord	isocoord;
	int		angle;
	int		scale;

	angle = fdata->hookmods.angle;
	scale = fdata->hookmods.scale;
	x *= scale;
	y *= scale;
	z *= scale;
	isocoord.rowx = (x - y) *  -cos(rad(angle));
	isocoord.coly = -z + (x + y) * sin(rad(angle));
	isocoord.rowx += fdata->img_size.rowx / 2;
	isocoord.coly += (fdata->img_size.coly - fdata->map.rowscols.coly * scale) / 2;
	return (isocoord);
}

t_coord	ft_para(t_fdfdata *fdata, int x, int y, int z)
{
	t_coord	paracoord;
	int		angle;
	int		scale;

	angle = fdata->hookmods.angle;
	scale = fdata->hookmods.scale;
	x *= scale;
	y *= scale;
	z *= scale;
	paracoord.rowx = (x + y) * -cos(rad(angle));
	paracoord.coly = -z + (x - y) * sin(rad(angle));
	paracoord.rowx += (fdata->img_size.rowx - fdata->map.rowscols.rowx)/ 2;
	paracoord.coly += (fdata->img_size.coly + fdata->map.rowscols.coly * scale) / 2;
	return (paracoord);
}

t_coord	parpro(int x, int y, int z)
{
	t_coord	parcoord;
	int		angle;

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
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}
