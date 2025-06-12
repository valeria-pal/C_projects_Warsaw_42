/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:45:46 by vpaliash          #+#    #+#             */
/*   Updated: 2025/06/12 19:41:11 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	main(void)
{
	t_mlx_data	mlx_data;

	mlx_data.mlx_connection = mlx_init();
	mlx_data.window = mlx_new_window(mlx_data.mlx_connection, WIDTH, HEIGHT,
			"Mandelbrot");
	mlx_data.image = mlx_new_image(mlx_data.mlx_connection, WIDTH, HEIGHT);
	mlx_data.pixel_address = mlx_get_data_addr(mlx_data.image,
			&mlx_data.bites_per_pixel, &mlx_data.line_length, &mlx_data.endian);
	draw_mandelbrot(&mlx_data, MAX_ITERATIONS);
	mlx_put_image_to_window(mlx_data.mlx_connection, mlx_data.window,
		mlx_data.image, 0, 0);
	mlx_loop(mlx_data.mlx_connection);
	return (0);
}
