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

int	mandelbrot_iterations(int x, int y, int max_iterations)
{
	t_complex	c;
	t_complex	z;
	int			iterations;
	double		z_re2;
	double		z_im2;

	c = pixel_to_complex(x, y);
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
