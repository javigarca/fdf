#include "fdf.h"

void	ft_light_my_pixel(t_fdfdata *fdata, int x, int y, int color)
{
	int	*lpixel;

	lpixel = (int*)fdata->imgadd;
	if (x >= 0 && x < fdata->win_size.rowx && y >= 0 && y < fdata->win_size.coly)
		lpixel[x + fdata->win_size.rowx * y] = color;
}
