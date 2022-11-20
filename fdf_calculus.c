#include "fdf.h"

t_coord isopro(int x, int y, int z)
{
	t_coord isocoord;
	int angle;

	angle = 30;
	isocoord.rowx = (x - y) * cos(rad(angle));
	isocoord.coly = ((x + y) * sin(rad(angle)) - z);
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
