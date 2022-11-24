#include "fdf.h"

int	ft_key_press(int key, t_fdfdata *fdata)
{

	if (key == 53)
		exit(0);
	if (key == 69 || key == 24 || key == 78 || key == 27)
		ft_scale(key, fdata);
	else if (key == 123 || key == 124
		|| key == 125 || key == 126)
		ft_axis_displ(key, fdata);
	else if ((key >= 83 && key <90) || key == 91 || key == 92)
		ft_rotate_view(key, fdata);/*
	else if (key == MAIN_PAD_LESS || key == MAIN_PAD_MORE)
		flatten(key, fdf);*/
	else if (key == 9)
		ft_change_view(key, fdata);
	return (0);
}
/*
int			mouse_press(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		zoom(button, fdf);
	else if (button == MOUSE_LEFT_BUTTON)
		fdf->mouse->is_pressed = true;
	return (0);
}


** Handle mouse release


int			mouse_release(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	(void)button;
	fdf = (t_fdf *)param;
	fdf->mouse->is_pressed = false;
	return (0);
}


** Handle mouse move


int			mouse_move(int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	fdf->mouse->previous_x = fdf->mouse->x;
	fdf->mouse->previous_y = fdf->mouse->y;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (fdf->mouse->is_pressed)
	{
		fdf->camera->beta += (x - fdf->mouse->previous_x) * 0.002;
		fdf->camera->alpha += (y - fdf->mouse->previous_y) * 0.002;
		draw(fdf->map, fdf);
	}
	return (0);
}
*/
