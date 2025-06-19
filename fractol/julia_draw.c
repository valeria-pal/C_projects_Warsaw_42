/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:41:22 by vpaliash          #+#    #+#             */
/*   Updated: 2025/06/19 15:38:24 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	julia_iterations(t_complex z, t_complex c, int max_iterations)
{
	int		iterations;
	double	z_re2;
	double	z_im2;

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

void	draw_julia(t_fractal_data *fractal, t_complex c, int max_iterations)
{
	int			x;
	int			y;
	int			iterations;
	int			color;
	t_complex	z;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z = pixel_to_complex(x, y, &fractal->view);
			iterations = julia_iterations(z, c, max_iterations);
			color = get_color(iterations, max_iterations);
			draw_pixel_on_image(&fractal->mlx, x, y, color);
			x++;
		}
		y++;
	}
}
