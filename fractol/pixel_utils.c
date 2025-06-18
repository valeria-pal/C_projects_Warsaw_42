/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:11:47 by vpaliash          #+#    #+#             */
/*   Updated: 2025/06/18 18:21:32 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	create_rgb(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}
int	get_color(int iterations, int max_iterations)
{
	int		red;
	int		green;
	int		blue;
	double	t;

	if (iterations == max_iterations)
		return (create_rgb(0, 0, 0));
	t = (double)iterations / max_iterations;
	red = (int)(9 * (1 - t) * t * t * t * 255);
	green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (create_rgb(red, green, blue));
}
void	draw_pixel_on_image(t_mlx_data *mlx_data, int x, int y, int color)
{
	unsigned int	*pixel_ptr;
	int				bytes_per_pixel;
	int				offset;

	bytes_per_pixel = mlx_data->bites_per_pixel / 8;
	offset = y * mlx_data->line_length + x * bytes_per_pixel;
	pixel_ptr = (unsigned int *)(mlx_data->pixel_address + offset);
	*pixel_ptr = color;
}
t_complex	pixel_to_complex(int x, int y, t_viewing_window *view)
{
	t_complex c;
	c.re = view->min_re + (x * (view->max_re - view->min_re) / WIDTH);
	c.im = view->min_im + (y * (view->max_im - view->min_im) / HEIGHT);
	return (c);
}