#include "fdf.h"

void	ft_light_my_pixel(t_fdfdata *fdata, int x, int y, int color)
{
	int lpixel;
	int	width;
	int	height;

	width = fdata->img_size.rowx;
	height = fdata->img_size.coly;
//		lpixel = (x * fdata->pixel_b / 8) + (y * fdata->lines_b);
	if (x >= 0 && x < width && y >= 0 && y < height)
	{
		lpixel = (x * fdata->pixel_b / 8) + (y * fdata->lines_b);
		fdata->imgadd[lpixel] = color;
		fdata->imgadd[++lpixel] = color >> 8;
		fdata->imgadd[++lpixel] = color >> 16;
	}
//	else
//		printf("pix: %i", lpixel);
		
}

void	ft_draw_menu(t_fdfdata *fdata)
{
	char *line;
	char *name;

	name = fdata->map_name;
	line = "Mapa: ";
	mlx_string_put(fdata->mlx, fdata->win, 10, 5, 0xAAAFFF, line);
	mlx_string_put(fdata->mlx, fdata->win, 65, 5, 0x02FFFF, name);
	line = "---------------------";
	mlx_string_put(fdata->mlx, fdata->win, 10, 15, 0xAAAFFF, line);
	line = "segunda linea: zoom";
	mlx_string_put(fdata->mlx, fdata->win, 10, 25, 0xAAAFFF, line);
	line = "Tercera linea";
	mlx_string_put(fdata->mlx, fdata->win, 10, 40, 0xAAAFFF, line);
	line = "cuarta linea";
	mlx_string_put(fdata->mlx, fdata->win, 10, 55, 0xAAAFFF, line);
}
