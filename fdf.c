#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdfdata	fdata;

	if (argc == 2)
	{
		fdfdata_init(&fdata);
//		fdata.mlx = mlx.init();
//		fdata.hooksmods.angle = 30;
		fdata.map = ft_read_map(argv[1]);

//		ft_putstr_fd("\nAHORA EL MAPA\n", 1);
/*		ft_print_map(fdata.map, fdata.map.rowscols.rowx, \
				fdata.map.rowscols.coly);*/
		ft_start_draw(&fdata);

	}
	else
		ft_putstr_fd("Type ./fdf <map.fdf>\n", 1);
	return (0);
}

void	fdfdata_init(t_fdfdata *fdata)
{
	fdata->mlx = mlx_init();
	fdata->win = mlx_new_window(fdata->mlx, 1280, 1024, "FDF");
	fdata->img = mlx_new_image(fdata->mlx, 1024, 1024);
	fdata->imgadd = mlx_get_data_addr(fdata->img, &fdata->pixel_b, &fdata->lines_b, &fdata->endian);
	fdata->hookmods.angle = 30;

}
