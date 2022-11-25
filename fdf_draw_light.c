/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:38:38 by javigarc          #+#    #+#             */
/*   Updated: 2022/11/25 14:30:58 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_light_my_pixel(t_fdfdata *fdata, int x, int y, int color)
{
	int	lpixel;
	int	width;
	int	height;

	width = fdata->img_size.rowx;
	height = fdata->img_size.coly;
	if (x >= 0 && x < width && y >= 0 && y < height)
	{
		lpixel = (x * fdata->pixel_b / 8) + (y * fdata->lines_b);
		fdata->imgadd[lpixel] = color;
		fdata->imgadd[++lpixel] = color >> 8;
		fdata->imgadd[++lpixel] = color >> 16;
	}
}

void	ft_draw_menu(t_fdfdata *fdata, char *line)
{
	mlx_string_put(fdata->mlx, fdata->win, 10, 15, TXT_CLR_A, " MAP: ");
	mlx_string_put(fdata->mlx, fdata->win, 65, 15, TXT_CLR_B, line);
	line = "------------------------------";
	mlx_string_put(fdata->mlx, fdata->win, 10, 30, DEF_CLR, line);
	line = "Move Axis X,Y: Arrow Keys";
	mlx_string_put(fdata->mlx, fdata->win, 10, 50, TXT_CLR_A, line);
	line = "Zoom: + | -";
	mlx_string_put(fdata->mlx, fdata->win, 10, 70, TXT_CLR_A, line);
	line = "Perspective: P";
	mlx_string_put(fdata->mlx, fdata->win, 10, 90, TXT_CLR_A, line);
	line = "Rotation";
	mlx_string_put(fdata->mlx, fdata->win, 10, 110, TXT_CLR_A, line);
	line = "       X Axis: Q | A";
	mlx_string_put(fdata->mlx, fdata->win, 10, 125, TXT_CLR_A, line);
	line = "       Y Axis: W | S";
	mlx_string_put(fdata->mlx, fdata->win, 10, 140, TXT_CLR_A, line);
	line = "       Z Axis: E | D";
	mlx_string_put(fdata->mlx, fdata->win, 10, 155, TXT_CLR_A, line);
	line = "Height: Z | X";
	mlx_string_put(fdata->mlx, fdata->win, 10, 175, TXT_CLR_A, line);
	line = "Terminate: ESC";
	mlx_string_put(fdata->mlx, fdata->win, 10, 195, TXT_CLR_A, line);
}

void	ft_clear_image(t_fdfdata *fdata, int color_a, int color_b)
{
	int	x;
	int	y;

	x = 0;
	while (x < fdata->win_size.rowx)
	{
		y = 0;
		while (y < fdata->win_size.coly)
		{
			if (y % 2)
				ft_light_my_pixel(fdata, x, y, color_a);
			else
				ft_light_my_pixel(fdata, x, y, color_b);
			++y;
		}
		++x;
	}
}

void	ft_light_line(t_fdfdata *fdata, t_coord begin, t_coord end, t_bnum num)
{
	while ((num.cur.rowx != end.rowx) || (num.cur.coly != end.coly))
	{
		ft_light_my_pixel(fdata, num.cur.rowx, num.cur.coly, \
				ft_get_color(num.cur, begin, end, num.delta));
		num.error[1] = num.error[0] * 2;
		if (num.error[1] > -(num.delta.coly))
		{
			num.error[0] -= num.delta.coly;
			num.cur.rowx += num.sign.rowx;
		}
		if (num.error[1] < num.delta.rowx)
		{
			num.error[0] += num.delta.rowx;
			num.cur.coly += num.sign.coly;
		}
	}
}
