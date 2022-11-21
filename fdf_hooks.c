#include "fdf.h"

int	key_close(int keypressed, t_fdfdata	*fdata)
{
	if (keypressed == 53)
	{
		fdata = NULL;
		exit(0);
	}
	return (0);
}

int	button_close(t_fdfdata *fdata)
{
	fdata = NULL;
	exit(0);
	return (0);
}
