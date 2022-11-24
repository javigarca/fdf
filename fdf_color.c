#include "fdf.h"

double ft_percent(int start, int end, int current)
{
    double placement;
    double distance;

    placement = current - start;
    distance = end - start;
    return ((distance == 0) ? 1.0 : (placement / distance));
}

int ft_get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

int ft_get_color(t_coord current, t_coord begin, t_coord end, t_coord delta)
{
    int     red;
    int     green;
    int     blue;
    double  percentage;

	if (current.color == end.color)
		return (current.color);
    if (delta.rowx > delta.coly)
        percentage = ft_percent(begin.rowx, end.rowx, current.rowx);
    else
        percentage = ft_percent(begin.coly, end.coly, current.coly);
    red = ft_get_light((begin.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
    green = ft_get_light((begin.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
    blue = ft_get_light(begin.color & 0xFF, end.color & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}

int		ft_dot_color(double percentage)
{
	if (percentage < 0.1)
		return (P10_CLR);
	else if (percentage < 0.2)
		return (P20_CLR);
	else if (percentage < 0.3)
		return (P30_CLR);
	else if (percentage < 0.4)
		return (P40_CLR);
	else if (percentage < 0.5)
		return (P50_CLR);
	else if (percentage < 0.6)
		return (P60_CLR);
	else if (percentage < 0.7)
		return (P70_CLR);
	else if (percentage < 0.8)
		return (P80_CLR);
	else if (percentage < 0.9)
		return (P90_CLR);
	else
		return (P00_CLR);
}
