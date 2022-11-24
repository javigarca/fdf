#include "fdf.h"

void	ft_rotate_x_axis(int *y, int *z, double x_angle)
{
	int prev_y;
	int prev_z;

	prev_y = *y;
	prev_z = *z;
	*y = prev_y * cos(x_angle) + prev_z * sin(x_angle);
	*z = -prev_y * sin(x_angle) + prev_z * cos(x_angle);
}

void	ft_rotate_y_axis(int *x, int *z, double y_angle)
{
	int prev_x;
	int prev_z;

	prev_x = *x;
	prev_z = *z;
	*x = prev_x * cos(y_angle) + prev_z * sin(y_angle);
	*z = -prev_x * sin(y_angle) + prev_z * cos(y_angle);
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
