#include "fdf.h"



int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
	double deltaX = endX - beginX;
	double deltaY = endY - beginY; // 0
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels; // 1
	deltaY /= pixels; // 0
	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
	    mlx_pixel_put(mlx, win, pixelX, pixelY, color);
	    pixelX += deltaX;
	    pixelY += deltaY;
	    --pixels;
	}
	return (0);
}

int	key_close(int keypressed, void *param)
{
	t_fdfdata *ftop = param;
	if (keypressed == 53)
	{
		mlx_destroy_window(ftop->mlx, ftop->win);
		exit(0);
	}
	return(0);
}

int	button_close(t_fdfdata *ftop)
{
	mlx_destroy_window(ftop->mlx, ftop->win);
	exit(0);
}


int	main(int argc, char **argv)
{
	t_fdfdata	ftop;
	int pixel_bits;
	int line_bytes;
	int endian;
	char *buffer;
	int color = 0x262342;
	int pixel;

	if (argc)
	{
		ftop.mlx = mlx_init();
		ftop.win = mlx_new_window(ftop.mlx, 1280, 1024, argv[0]);
	    mlx_clear_window(ftop.mlx, ftop.win);
		ftop.img = mlx_new_image(ftop.mlx, 1280, 1024);
		buffer = mlx_get_data_addr(ftop.img, &pixel_bits, &line_bytes, &endian);

	for(int y = 0; y < 100; ++y)
	{
		for(int x = 0; x < 200; ++x)
		{
			pixel = (y * line_bytes) + (x * 4);
			if (endian == 1)    // Most significant (Alpha) byte first
		    {
				buffer[pixel + 0] = (color); //>> 24);
		        buffer[pixel + 1] = (color); //>> 16) & 0xFF;
		        buffer[pixel + 2] = (color); //>> 8) & 0xFF;
		        buffer[pixel + 3] = (color); //& 0xFF;
		    }
			else if (endian == 0)   // Least significant (Blue) byte first
			{
		        buffer[pixel + 0] = (color) & 0xFF;
		        buffer[pixel + 1] = (color >> 8) & 0xFF;
		        buffer[pixel + 2] = (color >> 16) & 0xFF;
		        buffer[pixel + 3] = (color >> 24);
		    }
		}
	}

	mlx_put_image_to_window(ftop.mlx, ftop.win, ftop.img, 0, 0);
	color = 0x00FFFF;

	for(int y = 0; y < 100; ++y)
	{
		for(int x = 0; x < 200; ++x)
		{
			pixel = (y * line_bytes) + (x * 4);
			if (endian == 1)    // Most significant (Alpha) byte first
		    {
				buffer[pixel + 0] = (color); //>> 24);
		        buffer[pixel + 1] = (color); //>> 16) & 0xFF;
		        buffer[pixel + 2] = (color); //>> 8) & 0xFF;
		        buffer[pixel + 3] = (color); //& 0xFF;
		    }
			else if (endian == 0)   // Least significant (Blue) byte first
			{
		        buffer[pixel + 0] = (color) & 0xFF;
		        buffer[pixel + 1] = (color >> 8) & 0xFF;
		        buffer[pixel + 2] = (color >> 16) & 0xFF;
		        buffer[pixel + 3] = (color >> 24);
		    }
		}
	}

	mlx_put_image_to_window(ftop.mlx, ftop.win, ftop.img, 75, 75);
//		mlx_pixel_put(ftop.mlx, ftop.win, 300, 80, 15128832);
//		mlx_string_put(ftop.mlx, ftop.win, 340, 100, 10008832, argv[0]);
//		draw_line(ftop.mlx, ftop.win, 0, 0, 600, 180, 0xFF2233); // This should create a white horizontal line about 10 pixels long.
		mlx_key_hook(ftop.win, &key_close, &ftop);
		mlx_hook(ftop.win, 17, 0, &button_close, &ftop);
		mlx_loop(ftop.mlx);
	}

}
