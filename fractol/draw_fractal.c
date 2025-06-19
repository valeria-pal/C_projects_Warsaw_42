/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:45:41 by vpaliash          #+#    #+#             */
/*   Updated: 2025/06/19 15:38:13 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_fractal_data *fractal, int max_iterations)
{
	t_complex	c;

	c = fractal->julia_param;
	if (fractal->fractal_type == 0)
		draw_mandelbrot(fractal, max_iterations);
	else if (fractal->fractal_type == 1)
		draw_julia(fractal, c, max_iterations);
}
