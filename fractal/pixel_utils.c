/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:11:47 by vpaliash          #+#    #+#             */
/*   Updated: 2025/06/12 19:46:57 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	create_rgb(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}
int	get_color(int iterations, int max_iterations)
{
	int	red;
	int	green;
	int	blue;

	if (iterations == max_iterations)
		return (create_rgb(0, 0, 0));
	red = (int)(255.0 * iterations / max_iterations);
	green = (int)(255.0 * (1.0 - (double)iterations / max_iterations));
	blue = red / 2;
	return (create_rgb(red, green, blue));
}
void	draw_pixel_on_image(t_mlx_data *mlx_data, int x, int y, int color)
{
	unsigned int	*pixel_ptr;
	int	bytes_per_pixel;
	int	offset;

	bytes_per_pixel = mlx_data->bites_per_pixel / 8;
	offset = y * mlx_data->line_length + x * bytes_per_pixel;
	(unsigned int *)(mlx_data->pixel_address + offset);
	*pixel_ptr = color;
}
t_complex pixel_to_complex(int x, int y)
{
	t_complex c;
	c.re = MIN_RE + (x * (MAX_RE - MIN_RE) / WIDTH);
	c.im = MIN_IM + (y * (MAX_IM - MIN_IM) / HEIGHT);	
	return c;
}