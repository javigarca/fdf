#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdfdata	fdata;

	if (argc == 2)
	{
		
		fdata.map = ft_read_map(argv[1]);
		fdata.map_name = argv[1];
		fdfdata_init(&fdata);
//		ft_putstr_fd("\nAHORA EL MAPA\n", 1);
/*		printf("\nSon rows:%i y cols:%i.", fdata.map.rowscols.rowx, \
				fdata.map.rowscols.coly);
		ft_print_map(fdata.map, fdata.map.rowscols.rowx, \
				fdata.map.rowscols.coly);*/
		ft_start_draw(&fdata);
	}
	else
		ft_putstr_fd("Type ./fdf <map.fdf>\n", 1);
//	system ("leaks fdf");
	return (0);
}

void	fdfdata_init(t_fdfdata *fdata)
{
	fdata->mlx = mlx_init();
	fdata->win_size.rowx = 1600;
	fdata->win_size.coly = 900;
	fdata->img_size.rowx = 1280;
	fdata->img_size.coly = 720;
	fdata->win = mlx_new_window(fdata->mlx, fdata->win_size.rowx, fdata->win_size.coly, "FDF");
	fdata->img = mlx_new_image(fdata->mlx, fdata->img_size.rowx, fdata->img_size.coly);
	fdata->imgadd = mlx_get_data_addr(fdata->img, &fdata->pixel_b, &fdata->lines_b, &fdata->endian);
	fdata->hookmods.angle = 30;
	fdata->hookmods.scale = 15;
}
