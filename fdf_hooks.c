#include "fdf.h"

int	key_close(int keypressed, t_fdfdata	*fdata)
{
	if (keypressed == 53)
	{
	//	free(fdata->map.mapdots);
		fdata = NULL;
//		system ("leaks fdf");
		exit(0);
	}
	return (0);
}

int	button_close(t_fdfdata *fdata)
{
//	free(fdata->map.mapdots);
	fdata = NULL;
//	system ("leaks fdf");
	exit(0);
	return (0);
}
