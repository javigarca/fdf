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

# define DEF_CLR 0xFFFFFFFF

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <signal.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

typedef struct	s_coord
{
	int	rowx;
	int	coly;
}				t_coord;
typedef struct	s_dot
{
	int	hz;
	int	dotcolor;
}				t_dot;
typedef struct	s_map
{
	t_dot	**mapdots;
	t_coord	rowscols;
}				t_map;
typedef struct	s_fdfdata
{
	void	*mlx;
	void	*win;
	void	*img;
	t_map	map;
	t_mods	hookmods;

}				t_fdfdata;
typedef struct	s_mods
{
	int	angle;
}				t_mods;

t_map	ft_read_map(char *namefile);
t_dot	**ft_load_mapdots(int fd, int rows, int cols);
// Extras //
int		ft_countcols(const char *str, char c);
t_coord	ft_rows_cols_check(int fd);
void	ft_print_map(t_map maptoprint, int rows, int cols);
#endif
