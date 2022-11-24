#include "fdf.h"

void	ft_rotate_x_axis(int *y, int *z, double x_angle)
{
	int prev_y;

	prev_y = *y;
	*y = prev_y * cos(x_angle) + *z * sin(x_angle);
	*z = -prev_y * sin(x_angle) + *z * cos(x_angle);
}

void	ft_rotate_y_axis(int *x, int *z, double y_angle)
{
	int prev_x;

	prev_x = *x;
	*x = prev_x * cos(y_angle) + *z * sin(y_angle);
	*z = -prev_x * sin(y_angle) + *z * cos(y_angle);
}

void	ft_rotate_z_axis(int *x, int *y, double z_angle)
{
	int prev_x;
	int prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(z_angle) - prev_y * sin(z_angle);
	*y = prev_x * sin(z_angle) + prev_y * cos(z_angle);
}