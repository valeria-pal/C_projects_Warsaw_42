/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:44:50 by vpaliash          #+#    #+#             */
/*   Updated: 2025/06/03 21:08:35 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iterations(t_complex c, int max_iterations)
{
	t_complex	z;
	int			iterations;
	double		z_re2;
	double		z_im2;

	z.re = 0.0;
	z.im = 0.0;
	iterations = 0;
	while (iterations < max_iterations)
	{
		z_re2 = pow(z.re,2);
		z_im2 = pow(z.im,2);
		if (z_re2 + z_im2 > 4.0)
			break ;
		z.im = 2.0 * z.re * z.im + c.im;
		z.re = z_re2 - z_im2 + c.re;
		iterations++;
	}
	return (iterations);
}


static int	create_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}
int get_color(int iterations, int max_iterations)
{
	int red;
	int green;
	int blue;
	if (iterations == max_iterations)
	return create_rgb(0,0,0);

	red = (int)(255.0 * iterations / max_iterations);
	green = (int)(255.0 * (1.0 - (double)iterations / max_iterations));
	blue = red / 2;

	return (create_rgb(red, green, blue));
}


void draw_mandelbrot(int x, int y, int max_iterations)
{
	int start_x;
	int start_y;
	int iterations;
	int color;
	t_complex c;

	start_x = 0;
	start_y = 0;
	while(y < HEIGHT)
	{
while (x < WIDTH)
{
c = pixel_to_complex(x,y);
 iterations = mandelbrot_iterations(c,max_iterations);
 color = get_color(iterations, max_iterations);
 //my_mlx_pixel_put(data, x, y, color); // add struct for work wih mlx
start_x++;
	}
	start_y++;
}
}
