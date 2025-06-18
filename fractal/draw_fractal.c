/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:45:41 by vpaliash          #+#    #+#             */
/*   Updated: 2025/06/18 16:50:21 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_fractal_data *fractal, int max_iterations)
{
	if (fractal->fractal_type == 0)
		draw_mandelbrot(fractal, max_iterations);
	else if (fractal->fractal_type == 1)
		draw_julia(fractal, max_iterations);
}