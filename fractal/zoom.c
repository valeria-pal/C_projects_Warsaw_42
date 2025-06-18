/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:05:31 by vpaliash          #+#    #+#             */
/*   Updated: 2025/06/18 17:05:59 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(t_fractal_data *f, int x, int y, double zoom_factor)
{
	double	mouse_re;
	double	mouse_im;
	double	range_re;
	double	range_im;

	mouse_re = f->view.min_re + x * (f->view.max_re - f->view.min_re) / WIDTH;
	mouse_im = f->view.min_im + y * (f->view.max_im - f->view.min_im) / HEIGHT;
	range_re = (f->view.max_re - f->view.min_re) * zoom_factor;
	range_im = (f->view.max_im - f->view.min_im) * zoom_factor;
	f->view.min_re = mouse_re - range_re / 2.0;
	f->view.max_re = mouse_re + range_re / 2.0;
	f->view.min_im = mouse_im - range_im / 2.0;
	f->view.max_im = mouse_im + range_im / 2.0;
}
int	mouse_hook(int button, int x, int y, void *param)
{
	t_fractal_data	*f;
	double			zoom_factor;

	f = (t_fractal_data *)param;
	if (button == 4)
		zoom_factor = 0.9;
	else if (button == 5)
		zoom_factor = 1.1;
	else
		return (0);
	zoom(f, x, y, zoom_factor);
	draw_fractal(f, MAX_ITERATIONS);
	mlx_put_image_to_window(f->mlx.mlx_connection, f->mlx.window, f->mlx.image,
		0, 0);
	return (0);
}
