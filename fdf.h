/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:38:38 by javigarc          #+#    #+#             */
/*   Updated: 2022/07/13 15:38:55 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define DEF_CLR 0xAA00FF
# define BKG_CLR 0x005050
# define FT_ABS(X) (((X) < 0) ? (-(X)) : (X))

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

typedef struct s_coord
{
	int	rowx;
	int	coly;
}			t_coord;
typedef struct s_dot
{
	int	hz;
	int	dotcolor;
}			t_dot;
typedef struct s_map
{
	t_dot	**mapdots;
	t_coord	rowscols;
}			t_map;
typedef struct s_mods
{
	int	angle;
	int scale;
}			t_mods;
typedef struct s_bresnum
{
	int	dY;
	int dX;
	int IncYi;
	int IncYr;
	int IncXi;
	int IncXr;
	int X;
	int Y;
	int av;
	int	avI;
	int	avR;
}
			t_bresnum;
typedef struct s_fdfdata
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*imgadd;
	int		pixel_b;
	int		lines_b;
	int		endian;
	char	*map_name;
	t_map	map;
	t_mods	hookmods;
	t_coord	win_size;
	t_coord	img_size;

}			t_fdfdata;

void	fdfdata_init(t_fdfdata *fdata);
// Map //
t_map	ft_read_map(char *namefile);
t_dot	**ft_load_mapdots(int fd, int rows, int cols);
int		ft_countcols(const char *str, char c);
t_coord	ft_rows_cols_check(int fd);
void	ft_print_map(t_map maptoprint, int rows, int cols);
// Hooks //
int		ft_key_close(int key, t_fdfdata *fdata);
int		ft_button_close(t_fdfdata *fdata);
void	ft_scale(int key, t_fdfdata *fdata);
// Hooks Control //
int		ft_key_press(int key, t_fdfdata *fdata);
int		ft_mouse_press(int button, int x, int y, t_fdfdata *fdata);
int		ft_mouse_release(int button, int x, int y, t_fdfdata *fdata);
int		ft_mouse_move(int x, int y, t_fdfdata *fdata);
// Calculus //
double	rad(int deg);
t_coord	ft_iso(t_fdfdata *fdata, int x, int y, int z);
t_coord	ft_para(t_fdfdata *fdata, int x, int y, int z);
void	ft_swap(int *a, int *b);
// Draw //
void	ft_start_hooks(t_fdfdata *fdata);
void	ft_start_draw(t_fdfdata *fdata);
void	ft_start_line_row(t_fdfdata *fdata);
void	ft_start_line_col(t_fdfdata *fdata);
void	ft_draw_line(t_fdfdata *fdata, t_coord begin, t_coord end);
// Draw light //
void	ft_light_my_pixel(t_fdfdata *fdata, int x, int y, int color);
void	ft_draw_menu(t_fdfdata *fdata);
void	ft_clear_image(t_fdfdata *fdata, int color);
#endif
