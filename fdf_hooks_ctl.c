/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks_ctl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:38:38 by javigarc          #+#    #+#             */
/*   Updated: 2022/11/29 12:30:14 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_key_press(int key, t_fdfdata *fdata)
{
	if (key == 53)
	{
		fdata = NULL;
		ft_putstr_fd("\rTerminating.\nOK.", 1);
		exit(0);
	}
	if (key == 69 || key == 24 || key == 78 || key == 27)
		ft_scale(key, fdata);
	else if (key == 123 || key == 124
		|| key == 125 || key == 126)
		ft_axis_displ(key, fdata);
	else if ((key >= 0 && key <= 2) || (key >= 12 && key <= 14))
		ft_rotate_view(key, fdata);
	else if (key == 6 || key == 7)
		ft_change_height(key, fdata);
	else if (key == 35)
		ft_change_view(key, fdata);
	return (0);
}

int	ft_button_close(t_fdfdata *fdata)
{
	fdata = NULL;
	ft_putstr_fd("\rProgram terminated successfully", 1);
	exit(0);
	return (0);
}
