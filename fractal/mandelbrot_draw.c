/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:44:50 by vpaliash          #+#    #+#             */
/*   Updated: 2025/06/18 16:43:54 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mandelbrot_iterations(t_complex c, int max_iterations)
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
		z_re2 = z.re * z.re;
		z_im2 = z.im * z.im;
		if (z_re2 + z_im2 > 4.0)
			break ;
		z.im = 2.0 * z.re * z.im + c.im;
		z.re = z_re2 - z_im2 + c.re;
		iterations++;
	}
	return (iterations);
}

void	draw_mandelbrot(t_fractal_data *fractal, int max_iterations)
{
	int			start_x;
	int			start_y;
	int			iterations;
	int			color;
	t_complex	c;

	start_y = 0;
	while (start_y < HEIGHT)
	{
		start_x = 0;
		while (start_x < WIDTH)
		{
			c = pixel_to_complex(start_x, start_y, &fractal->view);
			iterations = mandelbrot_iterations(c, max_iterations);
			color = get_color(iterations, max_iterations);
			draw_pixel_on_image(&fractal->mlx, start_x, start_y, color);
			start_x++;
		}
		start_y++;
	}
}
