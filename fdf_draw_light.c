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
//		printf(".\r");
	}
//	else
//	{
//		printf("*\r");
//		printf("*\r");
//		printf("8\r");
//		printf("8\r");
//	}

		
}

void	ft_draw_menu(t_fdfdata *fdata)
{
	char *line;
	char *name;

	name = fdata->map_name;
	line = "Mapa: ";
	mlx_string_put(fdata->mlx, fdata->win, 10, 5, TXT_CLR_A, line);
	mlx_string_put(fdata->mlx, fdata->win, 65, 5, TXT_CLR_B, name);
	line = "------------------------------";
	mlx_string_put(fdata->mlx, fdata->win, 10, 20, DEF_CLR, line);
	line = "Axis X and Y: Arrow Keys";
	mlx_string_put(fdata->mlx, fdata->win, 10, 40, TXT_CLR_A, line);
	line = "Scale: + and -";
	mlx_string_put(fdata->mlx, fdata->win, 10, 60, TXT_CLR_A, line);
	line = "Perspective: V";
	mlx_string_put(fdata->mlx, fdata->win, 10, 80, TXT_CLR_A, line);
	line = "5a linea";
	mlx_string_put(fdata->mlx, fdata->win, 10, 100, TXT_CLR_A, line);
	line = "67rta linea";
	mlx_string_put(fdata->mlx, fdata->win, 10, 120, TXT_CLR_A, line);
}

void	ft_clear_image(t_fdfdata *fdata, int color_a, int color_b)
{
	int x;
	int y;

	x = 0;
	while (x < fdata->win_size.rowx)
	{
		y = 0;
		while (y < fdata->win_size.coly)
		{
			if (y%2)
				ft_light_my_pixel(fdata, x, y, color_a);
			else
				ft_light_my_pixel(fdata, x, y, color_b);
			++y;
		}
		++x;
	}
}
