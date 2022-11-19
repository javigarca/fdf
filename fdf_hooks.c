#include "fdf.h"

int	key_close(int keypressed, void *param)
{
	t_fdfdata *ftop = param;
	if (keypressed == 53)
	{
		mlx_destroy_window(ftop->mlx, ftop->win);
		exit(0);
	}
	return(0);
}

int	button_close(t_fdfdata *ftop)
{
	mlx_destroy_window(ftop->mlx, ftop->win);
	exit(0);
}
